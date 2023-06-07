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

private:
	shared_ptr<Quad> _player;
	shared_ptr<Transform> _bowTrans;
	shared_ptr<DunBow> _bow;
	shared_ptr<Transform> _bulletTrans;
	vector<shared_ptr<DunBullet>> _bullets;


	bool _spacePress = false;
	bool _spaceUp = true;

};

