#pragma once
class DunMob
{
public:
	DunMob();
	~DunMob();

	void Update();
	void Render();

	void SetPosition(Vector2 pos) { _col->GetTransform()->SetPosition(pos); }
	void TakeDamage(int amount) { _hp -= amount; }

	shared_ptr<RectCollider> GetCollider() { return _col; }

	bool IsActive() { return _hp > 0; }
	int GetHP() { return _hp; }

private:
	int _hp = 10;
	shared_ptr<RectCollider> _col;
	shared_ptr<Transform> _trans;
	shared_ptr<Quad> _quad;

};

