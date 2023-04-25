
#include "framework.h"
#include "LineCollisionScene.h"

LineCollisionScene::LineCollisionScene()
{
	_line1 = make_shared<Line>(Vector2(100, 300), Vector2(800, 200));
	_line2 = make_shared<Line>(Vector2(600, 600), Vector2(500, 500));
	constactPoint = make_shared<CircleCollider>(10, Vector2());
}

LineCollisionScene::~LineCollisionScene()
{
}

void LineCollisionScene::Update()
{
	_line2->_endPos = mousePos;
	HitResult result = _line2->IsCollision(_line1);



	if (result.isCollision)
	{
		_line1->SetRed();
		_line2->SetRed();
		constactPoint->SetCenter(result.contactPoint);

	}
	
	else 
	{
		_line1->SetBlue();
		_line2->SetGreen();
		result.contactPoint = Vector2(-1000, -1000);
		constactPoint->SetCenter(result.contactPoint);

	}
}

void LineCollisionScene::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
	constactPoint->Render(hdc);
}

