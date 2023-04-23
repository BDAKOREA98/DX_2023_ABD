#pragma once
class CircleCollider : public enable_shared_from_this<CircleCollider> , public Collider
{
public:
	
	
	CircleCollider() : Collider(Vector2(0.0f, 0.0f)) {};
	CircleCollider(float radius, Vector2 center);
	~CircleCollider();
	

	virtual void Update() override;
	virtual void Render(HDC hdc)override;


	void SetRadius(float radius) { _radius = radius; }
	float GetRadius() { return _radius; }

	virtual bool IsCollision(const Vector2& pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other)override;
	virtual bool IsCollision(shared_ptr<class RectCollider> other)override;

	
	
private:

	float _radius = 0.0f;

};

