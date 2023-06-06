#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_rect = make_shared<RectCollider>(Vector2 (50.0f,50.0f));
	_rect->GetTransform()->SetPosition(CENTER);
	_rectcol = make_shared<RectCollider>(Vector2 (50.0f,50.0f));
	_rectcol->GetTransform()->SetPosition(CENTER + Vector2(-100.0f, 0.0f));
	
	_Circle = make_shared<CircleCollider>(50.0f);
	_Circle->GetTransform()->SetPosition(CENTER);
	_Circlecol = make_shared<CircleCollider>(50.0f);
	_Circlecol->GetTransform()->SetPosition(CENTER + Vector2(100.0f, 0.0f));
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	if (_rect->IsCollision(_rectcol))
	{
		_rect->SetRed();
		_rectcol->SetBlue();
	}
	else if (_rect->IsCollision(_Circlecol))
	{
		_rect->SetRed();
		_Circlecol->SetBlue();
	}
	else if (_Circle->IsCollision(_rectcol))
	{
		_Circle->SetWhite();
		_rectcol->SetBlue();
	}
	else if (_Circle->IsCollision(_Circlecol))
	{
		_Circle->SetWhite();
		_Circlecol->SetBlue();
	}
	else
	{
		_rect->SetGreen();
		_rectcol->SetGreen();
		_Circle->SetGreen();
		_Circlecol->SetGreen();
	}

	



	_rectcol->Update();
	_Circlecol->Update();
	

	_rect->GetTransform()->SetPosition(MOUSE_POS);
	_rect->Update();
	_Circle->GetTransform()->SetPosition(MOUSE_POS);
	_Circle->Update();

}

void ColliderScene::Render()
{
	_rect->Render();
	_Circle->Render();
	_rectcol->Render();
	_Circlecol->Render();
}
