#pragma once
class Moster
{
public:

	enum State
	{
		IDLE,
		RUN,
		JUMP,
		ATTACK
	};
	Moster();
	~Moster();

	void Update();
	void Render();

	shared_ptr<CircleCollider> GetCollider() { return _col; }
	void CreateAction(string name, float speed = 0.1f, Action::Type type = Action::LOOP, CallBack callBack = nullptr);

private:
	shared_ptr<CircleCollider> _col;

	shared_ptr<Transform> _transform;
	vector<shared_ptr<Action>> _actions;
	vector<shared_ptr<Sprite_Clip>> _sprites;


	State _curState = State::IDLE;
	State _oldState = State::IDLE;
	

};

