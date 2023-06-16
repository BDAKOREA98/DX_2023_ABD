#pragma once
class DunBullet
{
public:
	DunBullet();
	~DunBullet();

	void Update();
	void Render();

	void SetPos(Vector2 pos) { _pos = pos; }
	void SetDir(Vector2 dir) { _dir = dir.NorMalVector2(); }

	void SetActive(bool active) { _isActive = active; }
	bool IsActive() { return _isActive; }

	shared_ptr<Transform> GetTrans() { return _quadtrans; }
	shared_ptr<CircleCollider> GetCol() { return _col; }

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Transform> _quadtrans;
	shared_ptr<CircleCollider> _col;

	Vector2 _pos = Vector2();
	Vector2 _dir = Vector2();
	float _speed = 0.90f;

	bool _isActive = false;
};

