#include "framework.h"
#include "Moster.h"

Moster::Moster()
{
	_col = make_shared<CircleCollider>(100.0f);
	_transform = make_shared<Transform>();

	_col->GetTransform()->SetPosition(CENTER + Vector2(300.0f, 0.0));
	_transform->SetParent(_col->GetTransform());

	CreateAction("Clown_Intro_1");
	_actions[State::IDLE]->Play();
}

Moster::~Moster()
{
}

void Moster::Update()
{
	_transform->Update();
	_col->Update();

	_actions[_curState]->Update();

	_sprites[_curState]->SetCurClip(_actions[_curState]->GetCurClip());
	_sprites[_curState]->Update();
}

void Moster::Render()
{
	_transform->SetWorldBuffer(0);
	_col->Render();

	_sprites[_curState]->Render();
}

void Moster::CreateAction(string name, float speed, Action::Type type, CallBack callBack)
{
	// srv만드는 작업
	// IDLE, RUN
	wstring wName = wstring(name.begin(), name.end());
	wstring srvPath = L"Resource/CupHead/boss/BossClown/" + wName + L".png";
	shared_ptr<SRV> srv = ADD_SRV(wName);

	// xmldocument 만들기
	string xmlPath = "Resource/CupHead/boss/BossClown/" + name + ".xml";
	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	document->LoadFile(xmlPath.c_str());

	tinyxml2::XMLElement* textureAtlas = document->FirstChildElement();
	tinyxml2::XMLElement* row = textureAtlas->FirstChildElement();

	vector<Action::Clip> clips;

	float averageW = 0;
	float averageH = 0;
	int count = 0;
	while (true)
	{
		if (row == nullptr)
		{
			break;
		}
		// row에서 필요한 값을 인트형 변환 후 클립에 담기
		int x = row->FindAttribute("x")->IntValue();
		int y = row->FindAttribute("y")->IntValue();
		int w = row->FindAttribute("w")->IntValue();
		int h = row->FindAttribute("h")->IntValue();

		averageW += w;
		averageH += h;
		count++;


		Action::Clip clip = Action::Clip(x, y, w, h, srv);
		clips.push_back(clip);
		// 다음 자식으로 넘어가기
		row = row->NextSiblingElement();
	}

	shared_ptr<Action> action = make_shared<Action>(clips, name, type, speed);
	action->SetEndEvent(callBack);

	_actions.push_back(action);

	shared_ptr<Sprite_Clip> sprite = make_shared<Sprite_Clip>(srvPath, Vector2(averageW / count, averageH / count));
	_sprites.push_back(sprite);
}
