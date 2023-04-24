
#include "framework.h"
#include "LineCollisionScene.h"

LineCollisionScene::LineCollisionScene()
{
	_line1 = make_shared<Line>(Vector2(100, 300), Vector2(800, 200));
	_line2 = make_shared<Line>(Vector2(600, 600), Vector2(500, 500));
}

LineCollisionScene::~LineCollisionScene()
{
}

void LineCollisionScene::Update()
{
	_line2->_endPos = mousePos;

	if (isIntersect(_line2, _line1))
	{
		_line1->SetBlue();
		_line2->SetGreen();
		

	}
	else 
	{
		_line1->SetRed();
		_line2->SetRed();
		
	}
}

void LineCollisionScene::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
}

bool LineCollisionScene::isIntersect(shared_ptr<Line> s1, shared_ptr<Line> s2)
{
	// 첫번째 선분의 시작지점x,y = x1,y1
// 첫번째 선분의 끝지점 x,y = x2,y2
// 두번째 선분의 시작지점 x,y = x3, y4
// 두번째 선분의 끝지점 x,y = x4,y4

#pragma region 


	Vector2 direction1 = { _line1->_endPos - _line1->_startPos }; // lin1방향
	Vector2 direction2 = { _line2->_endPos - _line2->_startPos }; // lin2방향
	float dot = direction1.Dot(direction2); // 내적
	float norm1 = sqrt(direction1.x * direction1.x + direction1.y * direction1.y); //line1크기
	float norm2 = sqrt(direction2.x * direction2.x + direction2.y * direction2.y); // line2크기
	float angle = acos(dot / (norm1 * norm2)); // 두선분이 이루는 각도
	float cross = _line1->_endPos.Cross(_line1->_startPos);
	float cross2 = _line2->_endPos.Cross(_line2->_startPos);
	float x = angle;
	float cross3 = cross * cross2 * sin(x * PI / 180.0);
	float cross4 = norm1 * norm2 * sin(x * PI / 180.0);
	if (cross3 > 0)
	{
		return true;
	}
	else if (cross == 0 && cross2 ==0)
	{
		return true;
	}
	else if (cross3 == 0)
	{
		return false;
	}
	else if (cross3 < 0)
	{
		return false;
	}
	else 
	{
		return false;
	}

	return true;

}
#pragma endregion

Vector2 LineCollisionScene::getIntersection(shared_ptr<Line> s1, shared_ptr<Line> s2)
{

	float start1_X = s1->StartX(), start_1Y = s1->StartY();
	float end1_X = s1->EndX(), end_1Y = s1->EndY();
	float start2_X = s2->StartX(), start_2Y = s2->StartY();
	float end2_X = s1->EndX(), end_2Y = s1->EndY();
	
	float denom = (end_2Y - start_2Y) * (end1_X - start1_X) - (end2_X - start2_X) * (end_1Y - start_1Y);
	float ua = ((end2_X - start2_X) * (start_1Y - start_2Y) - (end_2Y - start_2Y) * (start1_X - start2_X)) / denom;
	float x = start1_X + ua * (end1_X - start1_X);
	float y = start_1Y + ua * (end_1Y - start_1Y);

	Vector2 intersectionPoint = { x, y };
	return intersectionPoint;
}
