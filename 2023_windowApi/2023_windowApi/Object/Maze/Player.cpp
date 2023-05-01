#include "framework.h"
#include "Player.h"

Player::Player(shared_ptr<Maze> maze)
	: _maze(maze)
{
	if (_maze.expired() == false) // 유효하다
	{

		_startPos = _maze.lock()->StartPos();
		_endPos = _maze.lock()->EndPos();
		_maze.lock()->block(_startPos.x, _startPos.y)->SetType(MazeBlock::BlockType::PLAYER);
	}
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::RightHand()
{
}
