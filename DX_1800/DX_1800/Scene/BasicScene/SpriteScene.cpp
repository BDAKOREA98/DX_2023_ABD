#include "framework.h"
#include "SpriteScene.h"
#include "../../Framework/Animation/Action.h"

SpriteScene::SpriteScene()
{
	CreateAction();
	_sprite = make_shared<Sprite_Clip>(L"Resource/Sprite/zelda.png", Vector2(150,150));
	_trans = make_shared<Transform>();
	_trans->SetPosition(CENTER);


}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_trans->Update();
	_action->Update(); 
	_sprite->SetCurClip(_action->GetCurClip());
	_sprite	->Update();
}

void SpriteScene::Render()
{
	_trans->SetWorldBuffer(0);
	_sprite	->Render();
}

void SpriteScene::PostRender()
{
	ImGui::SliderFloat2("CurFrame", (float*)&_curFrame.x, 0, 10);

	ImGui::Text(_event.c_str());
	ImGui::Text("_eventNum : %d", _eventNumber);
	
	
	//_sprite->SetCurFrame(_curFrame);
}

void SpriteScene::CreateAction()
{
	vector<Action::Clip> clips;
	shared_ptr<SRV> srv = ADD_SRV(L"Resource/Sprite/zelda.png");
	Vector2 imageSize = srv->GetImageze();
	Vector2 maxFrame = { 10,8 };
	Vector2 size;

	size.x = imageSize.x / maxFrame.x;
	size.y = imageSize.y / maxFrame.y;
	//RUN 1
	for(int i = 0; i < 10; i++)
	{
		Vector2 startPos = Vector2((i* imageSize.x)/(maxFrame.x), imageSize.y * 4.0f / (maxFrame.y));
		Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
		clips.push_back(clip);

	}

	_action = make_shared<Action>(clips, "F_RUN", Action::END);
	_action->Play();
	_action->SetEndEvent(std::bind(&SpriteScene::EndEvent, this));
	//_action->SetNumEvent(std::bind(&SpriteScene::EndEventNum, this, std::placeholders::_1));
	_action->SetNumEvent(std::bind([this](int a)->void { this->_eventNumber = a; }, 5));

}
