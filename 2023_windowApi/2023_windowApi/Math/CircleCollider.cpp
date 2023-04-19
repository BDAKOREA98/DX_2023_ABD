#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider()
{}
CircleCollider::CircleCollider(float radius, Vector2 center)
	: _radius(radius), _center(center)
{

}
CircleCollider::~CircleCollider()
{}



void CircleCollider::Update()
{

}

void CircleCollider::Render(HDC hdc)
{
	float LEFT = _center.x + _radius;
	float RIGHT = _center.x - _radius;
	float TOP = _center.y - _radius;
	float BOTTOM = _center.y + _radius;
	Ellipse(hdc, LEFT, TOP, RIGHT, BOTTOM);

}
