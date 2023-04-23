#pragma once

class RectCollider;
class CircleCollider;

class Collider
{
public:

	enum class Type
	{
		NONE,
		CIRCLE,
		RECT
	};
	
	Collider(Vector2 center);
	virtual ~Collider();

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	 void SetCenter(const Vector2& center);
	 Vector2 GetCenter() { return _center; }

	
	 bool IsCollision(shared_ptr<Collider> other);
	 virtual bool IsCollision(const Vector2& pos) abstract;
	 virtual bool IsCollision(shared_ptr<class RectCollider> other) abstract;
	 virtual bool IsCollision(shared_ptr<class CircleCollider> other) abstract;


	void SetRed() { _curPenIdex = 1; }
	void SetGreen() { _curPenIdex = 0; }
	void SetBlue() { _curPenIdex = 2; }

protected:

	void CreatePens();

	

	int _curPenIdex = 0;
	vector<HPEN> _pens;

	Vector2 _center{ 0.0f, 0.0f };
	Type _type = Collider::Type::NONE;


};

