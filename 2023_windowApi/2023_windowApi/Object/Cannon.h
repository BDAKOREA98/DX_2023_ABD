#pragma once
class Cannon
{
public:

	Cannon();
	~Cannon();

	void Update();
	void Rneder(HDC hdc);

	void MoveByInput();
	void Fire();

	shared_ptr<Bullet> Setbullet();

private:
	shared_ptr<CircleCollider> _body;
	

	Vector2 _pos = CENTER;

	float _speed = 1.5f;
	

	//barrel
	shared_ptr<Line> _barrel;
	Vector2 _direction;
	float _barrelLength = 100.0f;
	float _angle = 0.0f;



	// 미리 총알을 생성 해 놓은 후 필요할 때만 풀에서 껏다 켰다 반복
	// 이를 오브젝트 풀링이라 부른다.
	// 

	float _power;
	vector<shared_ptr<Bullet>> _bullets;
	


};

