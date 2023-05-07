#include "framework.h"

#include "ArkanoidScene.h"

ArkanoidScene::ArkanoidScene()
{
	_stage = make_shared<Stage>();
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_stage->Update();
}

void ArkanoidScene::Render(HDC hdc)
{
	_stage->Render(hdc);
}
