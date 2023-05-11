#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void Move();
	bool Collision(shared_ptr<class Brick> brick);
private:
	friend class Stage;
	friend class Bar;


	shared_ptr<Collider> _ball;


	Vector2 _direction = { 0,10 };

	Vector2 _pos;

	float _time = 0;



};

