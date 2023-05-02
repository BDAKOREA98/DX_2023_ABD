#pragma once
class Brick
{
public:
	enum class BrickkType
	{
		BRICK,
		STAGE,
		NONE
	};
	Brick();
	~Brick();

	void Update();
	void Render(HDC hdc);
	void SetPosition(Vector2 pos) { _rect->SetCenter(pos); }

	void SetType(Brick::BrickkType type) { _type = type; }
	Brick::BrickkType GetType() { return _type; }

private:
	friend class Stage;

	BrickkType _type = BrickkType::NONE;

	shared_ptr<Collider> _rect;
	vector<HBRUSH> _brushes;
};

