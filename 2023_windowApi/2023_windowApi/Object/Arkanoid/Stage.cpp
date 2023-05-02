#include "framework.h"
#include "Stage.h"

Stage::Stage()
{
	_stage = make_shared<RectCollider>(CENTER, Vector2(WIN_WIDTH/2, WIN_HEIGHT) );
	_bar = make_shared<Bar>();
	_ball = make_shared<Ball>();
	
	



	Vector2 offset = Vector2(910,200);



	_brick.resize(25);
	for (int y = 0; y < _poolCountY; y++)
	{
		_brick[y].reserve(25);

		for (int x = 0; x < _poolCountX; x++)
		{
			shared_ptr<Brick> brick = make_shared<Brick>();

			brick->SetPosition(offset - Vector2(60 * x, 50 * y));
			brick->SetType(Brick::BrickkType::BRICK);
			_brick[y].push_back(brick);
			
		}
	}
	


}

Stage::~Stage()
{

}
void Stage::Update()
{
	_bar->Update();

	_ball->Update();

	_stage->Update();
	
	for (auto brickArr : _brick)
	{
		for (auto block : brickArr)
		{
			block->Update();
		}
	}

}

void Stage::Render(HDC hdc)
{
	HBRUSH hBrush = CreateSolidBrush(GRAY);
	SelectObject(hdc, hBrush);
	_stage->Render(hdc);
	DeleteObject(hBrush);

	_bar->Render(hdc);
	_ball->Render(hdc);


	for (auto brickArr : _brick)
	{
		for (auto block : brickArr)
		{
			block->Render(hdc);
		}
	}



	//SelectObject(hdc, _brushes[static_cast<unsigned int>(_type)]);
	
	
}
