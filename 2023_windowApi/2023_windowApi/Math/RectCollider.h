#pragma once
class RectCollider
{
public:
	RectCollider();

	~RectCollider();

	RectCollider(Vector2 size, Vector2 center);

	void Update();
	void Render(HDC hdc);

	void SetCenter(Vector2 pos) { _center = pos; }
	const Vector2& GetCenter() { return _center; }

	float Left() const { return _center.x - _size.x * 0.5f; }
	float Right() const { return _center.x + _size.x * 0.5f; }
	float Bottom() const { return _center.y + _size.y * 0.5f; }
	float Top() const { return _center.y - _size.y * 0.5f; }
	

	bool IsCollision(Vector2 pos);
	bool IsCollision(shared_ptr<RectCollider> other);


	void SetRed() { _curPenIdex = 1; }
	void SetGreen() { _curPenIdex = 0; }
	void SetBlue() { _curPenIdex = 2; }
 

private:
	void CreatePens();

	int _curPenIdex = 0;
	vector<HPEN> _pens;
	

	
	Vector2 _size = { 0.0f , 0.0f };
	Vector2 _center = { 0.0f, 0.0f };

};

