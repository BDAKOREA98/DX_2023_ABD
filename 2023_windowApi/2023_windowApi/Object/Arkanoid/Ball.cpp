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
	
	
	_time += 0.4f;
	if (_time > 1.0f)
	{
		Move();
		_time = 0.0f;
	}
	
	
}

void Ball::Render(HDC hdc)
{
	HBRUSH hBrush = CreateSolidBrush(WHITE);
	SelectObject(hdc, hBrush);
	_ball->Render(hdc);
	DeleteObject(hBrush);
}


void Ball::Move()
{
	if (_start == true)
	{
		_direction = { 0,10 };
		_start = false;
	}
	_pos = _ball->GetCenter();

	_pos = _pos + _direction;
	

	_ball->SetCenter(_pos);
}
