#pragma once
class RectCollider : public Collider
{
public:
	RectCollider();
	RectCollider(Vector2 center, Vector2 size);
	virtual ~RectCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	virtual float Left() const { return _center.x - _size.x * 0.5f; }
	virtual float Right() const { return _center.x + _size.x * 0.5f; }
	virtual float Bottom() const { return _center.y + _size.y * 0.5f; }
	virtual float Top() const { return _center.y - _size.y * 0.5f; }

	virtual bool IsCollision(const Vector2& pos) override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) override;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other) override;
	

	void SetSize(Vector2 size) { _size = size; }


private:
	Vector2 _size = { 0.0f , 0.0f };
	

};

