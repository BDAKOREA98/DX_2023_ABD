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



	// �̸� �Ѿ��� ���� �� ���� �� �ʿ��� ���� Ǯ���� ���� �״� �ݺ�
	// �̸� ������Ʈ Ǯ���̶� �θ���.
	// 

	float _power;
	vector<shared_ptr<Bullet>> _bullets;
	


};

