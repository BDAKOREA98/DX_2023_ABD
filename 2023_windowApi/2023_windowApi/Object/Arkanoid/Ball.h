#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void Move();
	bool _start = true;
private:
	friend class Stage;
	friend class Bar;


	shared_ptr<Collider> _ball;


	Vector2 _direction;

	Vector2 _pos;

	float _time = 0;



};

