#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_ball = make_shared<CircleCollider>(10, CENTER);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	_ball->Update();
}

void Ball::Render(HDC hdc)
{
	HBRUSH hBrush = CreateSolidBrush(WHITE);
	SelectObject(hdc, hBrush);
	_ball->Render(hdc);
	DeleteObject(hBrush);
}
