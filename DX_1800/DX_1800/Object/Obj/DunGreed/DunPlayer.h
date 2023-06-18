#pragma once
class DunPlayer
{
public:
	DunPlayer();
	~DunPlayer();

	void Update();
	void Render();


	void Fire();
	shared_ptr<DunBullet> SetBullet();

	void Move();
	void Attack();

	vector<shared_ptr<class DunBullet>>& GetBullet() {return _bullets;}
	shared_ptr<class DunMob> GetMob() { return _mob; }
private:
	shared_ptr<Quad> _player;
	shared_ptr<Transform> _playertrans;

	shared_ptr<Transform> _bowTrans;
	shared_ptr<Transform> _bowslot;
	shared_ptr<DunBow> _bow;

	

	shared_ptr<Transform> _bulletTrans;
	vector<shared_ptr<DunBullet>> _bullets;

	shared_ptr<class DunMob> _mob;

	bool _spacePress = false;
	bool _spaceUp = true;

};

