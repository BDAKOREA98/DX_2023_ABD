#pragma once
class Stage
{
public:
	Stage();
	~Stage();

	void Update();
	void Render(HDC hdc);

private:
	UINT _poolCountX = 10;
	UINT _poolCountY = 3;

	shared_ptr<RectCollider> _stage;
	shared_ptr<Ball> _ball;
	shared_ptr<Bar> _bar;
	vector<vector<shared_ptr<Brick>>> _brick;



};

