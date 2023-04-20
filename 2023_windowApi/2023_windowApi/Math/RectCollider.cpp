#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider()
{
}

RectCollider::RectCollider(float length, float width, Vector2 center)
	:_length(length),_width(width), _center(center)
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
	float LEFT = _center.x - _width;
	float RIGHT = _center.x + _width;
	float TOP = _center.y - _length;
	float BOTTOM = _center.y + _length;

	Rectangle(hdc, LEFT, TOP, RIGHT, BOTTOM);

}
