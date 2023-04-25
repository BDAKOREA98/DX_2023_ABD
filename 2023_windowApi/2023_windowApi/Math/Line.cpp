#include "framework.h"
#include "Line.h"


Line::~Line()
{
}

void Line::Update()
{
	for (auto pen : _pens)
		DeleteObject(pen);
}

void Line::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPenIdex]);

	MoveToEx(hdc, _startPos.x, _startPos.y, nullptr);
	LineTo(hdc, _endPos.x, _endPos.y);	
}

HitResult Line::IsCollision(shared_ptr<Line> other)
{
	HitResult result;
	result.col = nullptr;
	result.contactPoint = Vector2(-1000, -1000);
	result.isCollision = false;

	Vector2 a = _endPos - _startPos;
	Vector2 b = other->_endPos - other->_startPos;
	
	Vector2 atobStart = other->_startPos - _startPos;
	Vector2 atobEnd = other->_endPos - _endPos;

	Vector2 btoaStart = _startPos - other->_startPos;
	Vector2 btoaEnd = _endPos - other->_endPos;

	float leftTriangle = abs(a.Cross(atobStart));
	float rightTriangle = abs(a.Cross(btoaEnd));

	float t = (leftTriangle / (leftTriangle + rightTriangle));

	Vector2 contactPoint = other->_startPos + (other->_endPos - other->_startPos) * t;


	result.isCollision = a.IsBetween(atobStart, atobEnd) && b.IsBetween(btoaStart, btoaEnd);
	result.contactPoint = contactPoint;
	return result;
}

void Line::CreatePens()
{
	_curPenIdex = 0;
	_pens.emplace_back(CreatePen(PS_SOLID, 3, GREEN)); // 0
	_pens.emplace_back(CreatePen(PS_SOLID, 3, RED));   // 1
	_pens.emplace_back(CreatePen(PS_SOLID, 3, BLUE));   // 2
}
