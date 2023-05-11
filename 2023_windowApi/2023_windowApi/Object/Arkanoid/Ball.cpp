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
	
	
	Move();

	
	
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
	 
		
	
	_pos = _ball->GetCenter();

	_pos = _pos + (_direction.NorMalVector2()*5);
	

	_ball->SetCenter(_pos);
}



bool Ball::Collision(shared_ptr<class Brick> brick)
{
	if (_ball->IsCollision(brick->GetRect()) && brick->_active == true)
	{
		if (_ball->GetCenter().x > brick->GetRect()->Left() && _ball->GetCenter().x < brick->GetRect()->Right())
		{
			_direction.y = -_direction.y;
		}
		else if (_ball->GetCenter().y > brick->GetRect()->Top() && _ball->GetCenter().y < brick->GetRect()->Bottom())
		{
			_direction.x = -_direction.x;
		}
		else
		{
			bool xPos = _pos.x > brick->GetRect()->GetCenter().x;
			bool yPos = _pos.y > brick->GetRect()->GetCenter().y;

			Vector2 normal = Vector2(-1 + (2 * xPos), -1 + (2 * yPos)).NorMalVector2();

			if (_direction.Dot(normal) < 0)
				_direction = _direction - normal * _direction.Dot(normal) * 2;
			else if (fabsf(_direction.x) > fabsf(_direction.y))
			{
				_direction.y = -_direction.y;
			}
			else
			{
				_direction.x = -_direction.x;
			}
		}

		brick->_active = false;
		return true;
	}

	return false;
}
