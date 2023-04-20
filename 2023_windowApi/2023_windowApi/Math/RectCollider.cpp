#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider()
{
}

RectCollider::RectCollider(float length, Vector2 center)
	:_length(length), _center(center)
{

}


RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	float LEFT = _center.x - _length;
	float RIGHT = _center.x + _length;
	float TOP = _center.y - _length;
	float BOTTOM = _center.y + _length;

	Rectangle(hdc, LEFT, TOP, RIGHT, BOTTOM);

}
