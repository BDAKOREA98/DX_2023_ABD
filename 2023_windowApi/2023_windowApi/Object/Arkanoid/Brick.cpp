#include "framework.h"
#include "Brick.h"

Brick::Brick()
{
	_rect = make_shared<RectCollider>(Vector2(), Vector2(50, 40));

	HBRUSH brick = CreateSolidBrush(GREEN);
	HBRUSH stage = CreateSolidBrush(GRAY);
	
	_brushes.push_back(brick);
	_brushes.push_back(stage);

}

Brick::~Brick()
{
	for (auto brush : _brushes)
	{
		DeleteObject(brush);
	}
}

void Brick::Update()
{
	_rect->Update();
}

void Brick::Render(HDC hdc)
{
	if (_type == BrickkType::NONE)
	{
		return;
	}

	SelectObject(hdc, _brushes[static_cast<unsigned int>(_type)]);

	_rect->Render(hdc);
	
	

}
