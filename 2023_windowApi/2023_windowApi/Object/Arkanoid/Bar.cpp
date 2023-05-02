#include "framework.h"
#include "Bar.h"

Bar::Bar()
{
	
	_bar = make_shared<RectCollider>(Vector2(CENTER - Vector2(0,-200)), Vector2(100, 40));

}

Bar::~Bar()
{
}

void Bar::Update()
{

	MoveByInput();

}

void Bar::MoveByInput()
{
	
	
}


void Bar::Render(HDC hdc)
{
	HBRUSH hBrush = CreateSolidBrush(RED);
	SelectObject(hdc, hBrush);
	_bar->Render(hdc);
	DeleteObject(hBrush);
}

