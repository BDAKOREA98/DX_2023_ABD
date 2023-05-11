#pragma once
class Stage
{
public:
	Stage();
	~Stage();

	void Update();
	void Render(HDC hdc);

private:
	UINT _poolCountX = 8;
	UINT _poolCountY = 3;

	shared_ptr<RectCollider> _stage;
	shared_ptr<Ball> _ball;
	shared_ptr<Bar> _bar;
	vector<vector<shared_ptr<Brick>>> _brick;
	Vector2 _offset = Vector2((int)CENTER.x - BRICKSIZEX * 6 + (int)(BRICKSIZEX * 0.5f), BRICKSIZEY * 3);


};

