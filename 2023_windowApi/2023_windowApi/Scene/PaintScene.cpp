#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_circlecollider = make_shared<CircleCollider>(30, Vector2(400, 400));
	_rectcollider = make_shared<RectCollider>(50, 30, Vector2(100, 100));
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	//circlecollider
	Vector2 lerpPos = LERP(_circlecollider->GetCenter(), mousePos, 0.1f);
	_circlecollider->SetCenter(lerpPos);

	Vector2 lerpPos2 = LERP(_rectcollider->GetCenter(), mousePos, 0.8f);
	_rectcollider->SetCenter(lerpPos2);
}

void PaintScene::Render(HDC hdc)
{
	//_circlecollider->Render(hdc);
	_rectcollider->Render(hdc);
}