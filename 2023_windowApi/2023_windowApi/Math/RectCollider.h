#pragma once
class RectCollider
{
public:
	RectCollider();
	~RectCollider();

	RectCollider(float length, Vector2 center);

	void Update();
	void Render(HDC hdc);

	void SetCenter(Vector2 pos) { _center = pos; }
	const Vector2& GetCenter() { return _center; }

	void SetLength(float length) { _length = length; }
	float GetLength() { return _length; }

private:
	
	float _length = 0.0f;

	Vector2 _center = { 0.0f, 0.0f };

};

