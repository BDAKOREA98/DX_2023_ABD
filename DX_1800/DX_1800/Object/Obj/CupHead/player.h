#pragma once
//#include "../../../Types.h"
class player
{
public:
	enum State
	{
		IDLE,
		RUN,
		JUMP,
		ATTACK
	};




	player();
	~player();

	void Update();
	void Render();
	void PostRender();

	void CreateAction(string name, float speed = 0.1f, Action::Type type = Action::Type::LOOP, CallBack callBack = nullptr);

	void SetLEFT()
	{
		for (auto sprite : _sprites)
		{
			sprite->SetLeft();
		}
	}
	void SetRIGHT()
	{
		for (auto sprite : _sprites)
		{
			sprite->SetRight();
		}
	}

	void Jump();
	void Input();
	void Shoot();
	void SetAction(State state);

	shared_ptr<class Bullet> SetBullet();
	shared_ptr<class CircleCollider> GetCol() {return _col;	}

	bool _isFalling = false;
	bool _isAttack = false;

	State GetOldState() { return _oldState; }

	vector<shared_ptr<class Bullet>> GetBullet() { return _bullets; }
private:

	float _jumpPower = 0.0f;
	float _maxFalling = 500.0f;

	friend class CupHead;

	shared_ptr<CircleCollider> _col;
	vector<shared_ptr<Action>> _actions;
	State _state = State::IDLE;
	shared_ptr<Transform> _trans;
	vector<shared_ptr<Sprite_Clip>> _sprites;

	vector<shared_ptr<class Bullet>> _bullets;


	State _curState = State::IDLE;
	State _oldState = State::IDLE;

	shared_ptr<FilterBuffer> _filter;

	float _speed = 300;


};

