#include "framework.h"
#include "CupHeadScene.h"
#include "../../Object/Obj/CupHead/CupHead.h"

CupHeadScene::CupHeadScene()
{
	_cup = make_shared<CupHead>();

}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	_cup->Update();

}

void CupHeadScene::Render()
{
	_cup->Render();
	
}

void CupHeadScene::PostRender()
{
	_cup->PostRender();
}
