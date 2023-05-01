#include "framework.h"
#include "Maze.h"

Maze::Maze()
{

	Vector2 offset = Vector2(100, 100);
	//배열의 배열로 생성자를 돌아 2차원을 구현할때 왠만하면 Y부터

	_blocks.resize(25);
	for (int y = 0; y < _poolCountY; y++)
	{
		_blocks[y].reserve(25);

		for (int x = 0; x < _poolCountX; x++)
		{
			shared_ptr<MazeBlock> block = make_shared<MazeBlock>();
			
			block->SetPosition(offset + Vector2(17 * x, 17 * y));
			block->SetType(MazeBlock::BlockType::DISABLE);
			_blocks[y].push_back(block);
		}
	}

	CreateMaze();

}

Maze::~Maze()
{
}

void Maze::Update()
{

	for (auto blockArr : _blocks)
	{
		for (auto block : blockArr)
		{
			block->Update();
		}
	}
}

void Maze::Render(HDC hdc)
{
	for (auto blockArr : _blocks)
	{
		for (auto block : blockArr)
		{
			block->Render(hdc);
		}
	}
}


// 노드뚫기(홀수번째)
void Maze::CreateMaze()
{
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x%2 == 0 || y%2==0)
			{
				continue;
			}

			_blocks[y][x]->SetType(MazeBlock::BlockType::ABLE);
		}
	}

}
