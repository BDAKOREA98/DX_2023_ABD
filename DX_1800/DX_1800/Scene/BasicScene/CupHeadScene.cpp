#include "framework.h"
#include "CupHeadScene.h"
#include "../../Object/Obj/CupHead/player.h"

CupHeadScene::CupHeadScene()
{
	_player = make_shared<player>();

}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	_player->Update();

}

void CupHeadScene::Render()
{
	_player->Render();
	
}

void CupHeadScene::PostRender()
{
	_player->PostRender();
}
