#include "framework.h"
#include "RectCollider.h"





RectCollider::RectCollider()
	: Collider(Vector2(0, 0))
{
	_type = Collider::Type::RECT;
}

RectCollider::RectCollider(Vector2 center, Vector2 size)
	: Collider(center)
	, _size(size)
{
	_type = Collider::Type::RECT;
}


RectCollider::~RectCollider()
{
	
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPenIdex]);

	float LEFT = _center.x - (_size.x*0.5);
	float RIGHT = _center.x + (_size.x*0.5f);
	float TOP = _center.y - (_size.y*0.5f);
	float BOTTOM = _center.y + (_size.y*0.5f);

	Rectangle(hdc, LEFT, TOP, RIGHT, BOTTOM);

}



bool RectCollider::IsCollision(const Vector2& pos)
{
	if (Left() < pos.x && Right() > pos.x)
	{
		if (Top() < pos.y && Bottom() > pos.y)
		{
			return true;
		}
	}

	return false;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{

	if (Left() > other->Right() || Right() < other->Left() )
	{
		return false;
	}
	if (Top() > other->Bottom() || Bottom() < other->Top())
	{
		return false;
	}

	return true;
	
}
bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float circleBottom = other->GetCenter().y + other->GetRadius();
	float circleTop = other->GetCenter().y - other->GetRadius();
	float circleLeft = other->GetCenter().x - other->GetRadius();
	float circleRight = other->GetCenter().x + other->GetRadius();

	if (other->GetCenter().x < Right() && other->GetCenter().x > Left())
	{
		if (circleBottom > Top() && circleTop < Bottom())
		{
			return true;
		}
	}

	if (other->GetCenter().y < Bottom() && other->GetCenter().y > Top())
	{
		if (circleLeft < Right() && circleRight > Left())
		{
			return true;
		}
	}

	if (other->IsCollision(Vector2(Left(), Top()))
		|| other->IsCollision(Vector2(Right(), Top()))
		|| other->IsCollision(Vector2(Left(), Bottom()))
		|| other->IsCollision(Vector2(Right(), Bottom())))
	{
		return true;
	}

	return false;
}

