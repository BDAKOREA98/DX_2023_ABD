#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider()
{
	CreatePens();
}

RectCollider::RectCollider(Vector2 size, Vector2 center)
	: _center(center), _size(size)
{
	CreatePens();
}


RectCollider::~RectCollider()
{
	for (auto pen : _pens)
		DeleteObject(pen);
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

bool RectCollider::IsCollision(Vector2 pos)
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

void RectCollider::CreatePens()
{
	_curPenIdex = 0;
	_pens.emplace_back(CreatePen(PS_SOLID, 3, GREEN)); // 0
	_pens.emplace_back(CreatePen(PS_SOLID, 3, RED)); //1
	_pens.emplace_back(CreatePen(PS_SOLID, 3, BLUE));// 2
}

