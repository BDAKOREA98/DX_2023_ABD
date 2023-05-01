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
}

void ArkanoidScene::Render(HDC hdc)
{
	_stage->Render(hdc);
}
