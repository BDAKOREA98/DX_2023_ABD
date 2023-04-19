#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_circlecollider = make_shared<CircleCollider>(30, Vector2(400, 400));
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	//circlecollider의 중심 이 마우스를 따라 움직여라
	Vector2 lerpPos = LERP(_circlecollider->GetCenter(), mousePos,0.5f);
	_circlecollider->SetCenter(lerpPos);
}

void PaintScene::Render(HDC hdc)
{
	_circlecollider->Render(hdc);
}
