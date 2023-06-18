#include "framework.h"
#include "SpriteScene.h"

SpriteScene::SpriteScene()
{

	_sprite = make_shared<Sprite>(L"Resource/Sprite/zelda.png", Vector2(10, 8), Vector2(50,50));
	_trans = make_shared<Transform>();
	_trans->SetPosition(CENTER);
	_sprite->SetCurFrame(Vector2(0, 1));
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_sprite	->Update();
	_trans->Update();
}

void SpriteScene::Render()
{
	_trans->SetWorldBuffer(0);
	_sprite	->Render();
}

void SpriteScene::PostRender()
{
	ImGui::SliderFloat2("CurFrame", (float*)&_curFrame.x, 0, 10);
	_sprite->SetCurFrame(_curFrame);
}
