#include "framework.h"
#include "Effect.h"
#include "../../Types.h"
Effect::Effect(string name, wstring file, Vector2 maxFrame, Vector2 size, float speed, Action::Type type)
	:_name(name)
{
	_trans = make_shared<Transform>();
	CreateAction_ByFrame(name, file, maxFrame, size, speed, type);
	End();

}

Effect::Effect(string name, wstring file, wstring xmlPath, Vector2 size, float speed, Action::Type type)
	: _name(name)
{
	_trans = make_shared<Transform>();
	CreateAction_ByXML(name, file, xmlPath, size, speed, type);
	End();
}


Effect::~Effect()
{
}

void Effect::Update()
{
	if (_isActive == false)
		return;

	_trans->Update();
	
	// frame

	//if (_action == nullptr && _sprite == nullptr)
	//{
	//	return;
	//}
	//else if (_action !=nullptr && _sprite != nullptr)
	//{
	//	_action->Update();
	//	_sprite->SetCurClip(_action->GetCurClip());
	//	_sprite->Update();
	//}
	// xml

		_sprites[0]->Update();
		_sprites[0]->SetCurClip(_actions[0]->GetCurClip());
		_actions[0]->Update();
	

}

void Effect::Render()
{
	if (_isActive == false)
		return;

	_trans->SetWorldBuffer(0);
	////frame
	//if (_sprite == nullptr)
	//{
	//	return;
	//}
	//else
	//{
	//	_sprite->Render();
	//}
	//xml
	_sprites[0]->Render();
}

void Effect::Play(Vector2 pos)
{

	_isActive = true;

	_trans->SetPosition(pos);
	
	_actions[0]->Play();
}

void Effect::End()
{

	_isActive = false;
	_trans->SetPosition(Vector2(-10000.0f, -10000.0f));

}

void Effect::CreateAction_ByFrame(string name, wstring file, Vector2 maxFrame, Vector2 size, float speed, Action::Type type)
{
	// Action을 만드는 단계 (Frame별로 나뉘어져있기에)

	_sprite = make_shared<Sprite_Frame>(file, maxFrame, size);
	shared_ptr<SRV> srv = ADD_SRV(file);

	Vector2 clipSize = _sprite->GetImageSize();
	
	clipSize.x /= maxFrame.x;
	clipSize.y /= maxFrame.y;

	vector<Action::Clip> clips;

	for (int y = 0; y < maxFrame.y; y++)
	{
		for (int x = 0; x < maxFrame.x; x++)
		{
			Action::Clip clip = Action::Clip(x * clipSize.x, y * clipSize.y, clipSize.x, clipSize.y, srv);
			clips.push_back(clip);
		}

	}

	_action = make_shared<Action>(clips, name, type, speed);
	_action->SetEndEvent(std::bind(&Effect::End, this));


}

void Effect::CreateAction_ByXML(string name, wstring file, wstring xmlPath, Vector2 size, float speed, Action::Type type)
{


	// srv만드는 작업
	// IDLE, RUN
	
	shared_ptr<SRV> srv = ADD_SRV(file);

	// xmldocument 만들기
	
	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	string path = string(xmlPath.begin(), xmlPath.end());
	
	document->LoadFile(path.c_str());

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
	action->SetEndEvent(std::bind(&Effect::End, this));

	_actions.push_back(action);

	shared_ptr<Sprite_Clip> sprite = make_shared<Sprite_Clip>(file, Vector2(averageW / count, averageH / count));
	sprite->SetPS(ADD_PS(L"Shader/CupPS.hlsl"));
	_sprites.push_back(sprite);

}
