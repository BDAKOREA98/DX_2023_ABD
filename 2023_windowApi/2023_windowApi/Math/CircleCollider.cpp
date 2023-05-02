#include "framework.h"
#include "CircleCollider.h"




CircleCollider::CircleCollider(float radius, Vector2 center)
	: _radius(radius), Collider(center)
{
	_type = Collider::Type::CIRCLE;
}
CircleCollider::~CircleCollider()
{
}



void CircleCollider::Update()
{

}

void CircleCollider::Render(HDC hdc)
{
	//SelectObject(hdc, _pens[_curPenIdex]);


	float LEFT = _center.x + _radius;
	float RIGHT = _center.x - _radius;
	float TOP = _center.y - _radius;
	float BOTTOM = _center.y + _radius;
	Ellipse(hdc, LEFT, TOP, RIGHT, BOTTOM);

}

bool CircleCollider::IsCollision(const Vector2& pos)
{
	float distance = _center.Distance(pos);

	return distance <_radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float distance = _center.Distance(other->_center);

	return distance < _radius + other->GetRadius();


}
bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
	return other->IsCollision(shared_from_this());
}

