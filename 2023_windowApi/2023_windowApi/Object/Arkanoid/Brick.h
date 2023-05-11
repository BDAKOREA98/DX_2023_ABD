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
	
	
	void SetType(Brick::BrickkType type) { _type = type; }

	Brick::BrickkType GetType() { return _type; }

	shared_ptr<RectCollider> GetRect() { return dynamic_pointer_cast<RectCollider>(_rect); }
	
	void SetPosition(Vector2 pos) { _pos = pos; }
	void SetSize(Vector2 size) { _size = size; }

	bool _active = true;

private:
	friend class Stage;

	
	BrickkType _type = BrickkType::NONE;
	Vector2 _pos = CENTER;
	shared_ptr<Collider> _rect;
	Vector2 _size = Vector2(BRICKSIZEX, BRICKSIZEY);
	vector<HBRUSH> _brushes;
};

