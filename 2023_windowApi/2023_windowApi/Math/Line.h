#pragma once
#include "../Type.h"
class Line
{
public:
	Line(Vector2 start, Vector2 end) :_startPos(start), _endPos(end) { CreatePens(); }
	virtual ~Line();

	void Update();
	void Render(HDC hdc);

	void SetGreen() { _curPenIdex = 0; }
	void SetRed() { _curPenIdex = 1; }
	void SetBlue() { _curPenIdex = 2; }

	virtual float StartX() { return _startPos.x; }
	virtual float StartY() { return _startPos.y; }
	virtual float EndX() { return _endPos.x; }
	virtual float EndY() { return _endPos.y; }

	virtual Vector2 STARTPOSITION() { return _startPos; }
	virtual Vector2 ENDPOSITION() { return _endPos; }

	HitResult IsCollision(shared_ptr<Line> other);


public:
	void CreatePens();

	int _curPenIdex;
	vector<HPEN> _pens;

	Vector2 _startPos;
	Vector2 _endPos;
};

