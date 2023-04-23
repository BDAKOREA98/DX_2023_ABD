#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_mousecircle = make_shared<CircleCollider>(25, Vector2(400, 400));
	_circle = make_shared<CircleCollider>(80, Vector2(400, 400));
	_mouserect = make_shared<RectCollider>(Vector2(100, 50), Vector2(100, 100));
	_rect = make_shared<RectCollider>(Vector2(70, 80), Vector2(600, 300));

}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	//circlecollider
	Vector2 lerpPos = LERP(_mousecircle->GetCenter(), mousePos, 0.1f);
	_mousecircle->SetCenter(lerpPos);
	_mouserect->SetCenter(lerpPos);
#pragma region 점충돌

	/*if (_mousecircle->IsCollision(mousePos))
	{
		_mousecircle->SetBlue();
	}
	else
	{
		_mousecircle->SetGreen();
	}
	if (_mouserect->IsCollision(mousePos))
	{
		_mouserect->SetBlue();

	}
	else
	{
		_mouserect->SetGreen();
	}*/
	
#pragma endregion

#pragma region 같은도형충돌
	
	if (_mousecircle->IsCollision(_circle))
	{
		_mousecircle->SetRed();
		_circle->SetRed();
	}
	else
	{
		_mousecircle->SetGreen();
		_circle->SetGreen();
	}

	if (_mouserect->IsCollision(_rect))
	{
		_mouserect->SetRed();
			_rect->SetRed();
	}
	else
	{
		_mouserect->SetGreen();
		_rect->SetGreen();
	}
#pragma endregion

	if (_mouserect->IsCollision(_circle))
	{
		_mouserect->SetRed();
		_circle->SetRed();
	}
	else
	{
		_mouserect->SetGreen();
		_circle->SetGreen();
	}


}



void PaintScene::Render(HDC hdc)
{
	_mouserect->Render(hdc);
	_mousecircle->Render(hdc);
	_circle->Render(hdc);
	
	_rect->Render(hdc);
}