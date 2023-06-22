#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render();

	void SetPosition(Vector2 pos) { _col->GetTransform()->SetPosition(pos); }
	void SetDirtection(Vector2 dir) { _direction = dir.NorMalVector2(); _col->GetTransform()->SetAngle(dir.Angle()); }

	void CreateAction(string name, float speed = 0.1f, Action::Type type = Action::Type::LOOP, CallBack callBack = nullptr);


	void SetActiv(bool active) { _isActive = active; }
	bool GetActiv() { return _isActive; }


	shared_ptr<CircleCollider> GetCol() { return _col; }
	Vector2 GetDir() { return _direction; }

private:
	bool _isActive = false;

	shared_ptr<Sprite_Clip> _sprite;
	shared_ptr<Action> _action;
	shared_ptr<Transform> _transform;
	shared_ptr<CircleCollider> _col;

	Vector2 _direction;
	float _speed = 500.0f;
};

