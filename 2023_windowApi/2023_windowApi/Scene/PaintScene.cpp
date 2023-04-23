#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_mousecircle = make_shared<CircleCollider>(100, Vector2(400, 400));
	_circle = make_shared<CircleCollider>(80, Vector2(400, 400));
	_mouserect = make_shared<RectCollider>(Vector2(100, 100), Vector2(100, 100));
	_rect = make_shared<RectCollider>(Vector2(700, 500), Vector2(50, 70));

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

#pragma region 충돌시스템
	// 같은도형
	if (_mousecircle->IsCollision(_circle))
	{
		_mousecircle->SetBlue();
		_circle->SetBlue();
	}

	else if (_mouserect->IsCollision(_rect))
	{
		_mouserect->SetBlue();
			_rect->SetBlue();
	}
	else
	{
		_mousecircle->SetGreen();
		_circle->SetGreen();
		_mouserect->SetGreen();
		_rect->SetGreen();
	}
	//다른도형
	 if (_mousecircle->IsCollision(_rect))
	{
		_mousecircle->SetRed();
		_rect->SetRed();
	}
	else if (_mouserect->IsCollision(_circle))
	{
		_mouserect->SetRed();
		_circle->SetRed();
	}
	else
	{
		_mousecircle->SetGreen();
		_circle->SetGreen();
		_mouserect->SetGreen();
		_rect->SetGreen();
	}
	
#pragma endregion

	
	
	
	
}



void PaintScene::Render(HDC hdc)
{
	_mousecircle->Render(hdc);
	_mouserect->Render(hdc);

	_circle->Render(hdc);
	
	_rect->Render(hdc);
}