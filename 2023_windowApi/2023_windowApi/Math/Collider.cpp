#include "framework.h"
#include "Collider.h"




Collider::Collider(Vector2 center)
	: _center(center)
{
	CreatePens();
}

Collider::~Collider()
{
	for (auto pen : _pens)
		DeleteObject(pen);
}

void Collider::SetCenter(const Vector2& center)
{
	_center = center;
}

bool Collider::IsCollision(shared_ptr<class Collider> other)
{
	switch (other->_type)
	{
	case Collider::Type::NONE:
	{
		return false;
	}
	case Collider::Type::CIRCLE:
	{
		return IsCollision(dynamic_pointer_cast<CircleCollider>(other)); // 스마트포인터 다이나믹 캐스트
	}
	case Collider::Type::RECT:
	{
		return IsCollision(dynamic_pointer_cast<RectCollider>(other)); // 스마트포인터 다이나믹 캐스트
	}
	default:
		break;
	}

}

float Collider::Left() const
{
	return 0.0f;
}

float Collider::Right() const
{
	return 0.0f;
}

float Collider::Bottom() const
{
	return 0.0f;
}

float Collider::Top() const
{
	return 0.0f;
}



void Collider::CreatePens()
{
	_curPenIdex = 0;
	_pens.emplace_back(CreatePen(PS_SOLID, 3, GREEN)); // 0
	_pens.emplace_back(CreatePen(PS_SOLID, 3, RED)); //1
	_pens.emplace_back(CreatePen(PS_SOLID, 3, BLUE));// 2
}

