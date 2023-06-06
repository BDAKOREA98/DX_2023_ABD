#pragma once
#include "../../Types.h"

class RectCollider : public Collider
{
public:
	struct AABB_Info
	{
		float left = 0.0f;
		float top = 0.0f;
		float right = 0.0f;
		float bottom = 0.0f;
	};

	RectCollider(Vector2 size);
	virtual ~RectCollider();

	virtual void Update() override;
	virtual void Render() override;

	void CreateVertices();
	void CreateData();

	virtual bool IsCollision(const Vector2& pos) override;
	virtual bool IsCollision(shared_ptr<class CircleCollider> col) override;
	virtual bool IsCollision(shared_ptr<RectCollider> col)override;

	void SetScale(Vector2 scale);

	AABB_Info GetAABB_Info();

private:
	Vector2 _size;

};

