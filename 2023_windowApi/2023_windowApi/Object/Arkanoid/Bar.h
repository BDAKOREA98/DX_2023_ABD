#pragma once
class Bar
{

public:
	Bar();
	~Bar();

	void Update();
	void Render(HDC hdc);
	void MoveByInput();

	bool _iscontroll = true;


private:

	friend class Stage;
	friend class Ball;

	shared_ptr<Collider> _bar;

	Vector2 _pos;
	
	float _speed = 10;
};

