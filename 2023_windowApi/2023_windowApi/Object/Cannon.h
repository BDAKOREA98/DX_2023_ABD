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



	// 미리 총알을 생성 해 놓은 후 필요할 때만 풀에서 껏다 켰다 반복
	// 이를 오브젝트 풀링이라 부른다.
	// 
	bool _spacePress = false;
	bool _spaceUp = true;
	float _power; // 스페이스 누르면 증가하다 떼는 순간 불렛 스피드 수정
	vector<shared_ptr<Bullet>> _bullets;
	
	int _hp = 5;

};

