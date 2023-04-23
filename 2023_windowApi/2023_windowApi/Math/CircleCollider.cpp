#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider()
{
	 CreatePens();
}
CircleCollider::CircleCollider(float radius, Vector2 center)
	: _radius(radius), _center(center)
{
	CreatePens();
}
CircleCollider::~CircleCollider()
{
	for (auto pen : _pens)
		DeleteObject(pen);
}



void CircleCollider::Update()
{

}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPenIdex]);


	float LEFT = _center.x + _radius;
	float RIGHT = _center.x - _radius;
	float TOP = _center.y - _radius;
	float BOTTOM = _center.y + _radius;
	Ellipse(hdc, LEFT, TOP, RIGHT, BOTTOM);

}

bool CircleCollider::IsCollision(Vector2 pos)
{
	float distance = _center.Distance(pos);

	return distance <_radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float distance = _center.Distance(other->GetCenter());

	return distance < _radius + other->GetRadius();


}
//bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
//{
//	
//}


void CircleCollider::CreatePens()
{
	_curPenIdex = 0;
	_pens.emplace_back(CreatePen(PS_SOLID, 3, GREEN)); // 0
	_pens.emplace_back(CreatePen(PS_SOLID, 3, RED)); //1
	_pens.emplace_back(CreatePen(PS_SOLID, 3, BLUE));// 2
}
