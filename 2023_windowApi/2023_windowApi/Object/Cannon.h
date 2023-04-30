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


	void SetPostion(const Vector2& pos) { _pos = pos; }
	void TackeDamage() { _hp -= 1; }
	vector<shared_ptr<Bullet>>& GetBullets() { return _bullets; }
	shared_ptr<Collider > Getcol() { return _body; }

	bool _iscontroll = true;

	bool IsDead() { return _hp <= 0; }

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
	bool _spacePress = false;
	bool _spaceUp = true;
	float _power; // �����̽� ������ �����ϴ� ���� ���� �ҷ� ���ǵ� ����
	vector<shared_ptr<Bullet>> _bullets;
	
	int _hp = 5;

};

