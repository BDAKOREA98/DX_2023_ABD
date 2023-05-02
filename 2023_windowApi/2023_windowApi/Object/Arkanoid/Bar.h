#pragma once
class Bar
{

public:
	Bar();
	~Bar();

	void Update();
	void Render(HDC hdc);
	void MoveByInput();
private:
	shared_ptr<Collider> _bar;

	
	
	float _speed = 10;
};

