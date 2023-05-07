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
	_stage->Update();
	_ball->Update();
#pragma region Bar controll
	_bar->Update();

	if (_bar->_bar->Left() <= _stage->Left() )
	{
		_bar->_iscontroll = false;

		_bar->_pos.x = _bar->_bar->GetCenter().x + 10;
		_bar->_pos.y = _bar->_bar->GetCenter().y;
		_bar->_bar->SetCenter(_bar->_pos);

		if (_bar->_bar->Left()> _stage->Left())
		{
			_bar->_iscontroll = true;
		}
		
	}
	if (_bar->_bar->Right() >= _stage->Right())
	{
		_bar->_iscontroll = false;
		_bar->_pos.x = _bar->_bar->GetCenter().x - 10;
		_bar->_pos.y = _bar->_bar->GetCenter().y;
		_bar->_bar->SetCenter(_bar->_pos);

		if (_bar->_bar->Right() < _stage->Right())
		{
			_bar->_iscontroll = true;
		}
	}
	// 바와 볼의 충돌
	if (_bar->_bar->IsCollision(_ball->_ball))
	{
		_ball->_direction.x =  _ball->_ball->GetCenter().x-_bar->_bar->GetCenter().x  ;
		_ball->_direction.y =  _ball->_ball->GetCenter().y-_bar->_bar->GetCenter().y  ;
	}
	
	
	

	
#pragma endregion	
	
	
	#pragma region ball-stage contoll
	
	if (_stage->Left() >= _ball->_ball->Left())
	{
		_ball->_direction.x = abs(_ball->_direction.x);
		_ball->_direction.y = _ball->_direction.y;
	}
	else if (_stage->Right() <= _ball->_ball->Right())
	{
		_ball->_direction.x = -abs(_ball->_direction.x);
		_ball->_direction.y = _ball->_direction.y;
	}
	else if (_stage->Top() >= _ball->_ball->Top())
	{
		_ball->_direction.y = abs(_ball->_direction.y);
		_ball->_direction.x = _ball->_direction.x;
	}
	else if (_stage->Bottom() <= _ball->_ball->Bottom())
	{
		_ball->_direction.y = -abs(_ball->_direction.y);
		_ball->_direction.x = _ball->_direction.x;

	}
	
#pragma endregion
	
	

	

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
