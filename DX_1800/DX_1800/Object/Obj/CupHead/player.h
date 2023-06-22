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

private:

	float _jumpPower = 0.0f;
	float _maxFalling = 5000.0f;


	shared_ptr<CircleCollider> _col;
	vector<shared_ptr<Action>> _actions;
	State _state = State::IDLE;
	shared_ptr<Transform> _trans;
	vector<shared_ptr<Sprite_Clip>> _sprites;

	vector<shared_ptr<class Bullet>> _bullets;

	shared_ptr<class CupHeadBG> _background;

	State _curState = State::IDLE;
	State _oldState = State::IDLE;

	float _speed = 300;

	bool _isFalling = false;
	bool _isAttack = false;

};

