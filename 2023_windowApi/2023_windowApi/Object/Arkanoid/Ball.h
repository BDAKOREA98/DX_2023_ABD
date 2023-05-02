#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);
private:
	shared_ptr<CircleCollider> _ball;

};

