#include "framework.h"
#include "Maze.h"

Maze::Maze()
{

	Vector2 offset = Vector2(100, 100);
	//�迭�� �迭�� �����ڸ� ���� 2������ �����Ҷ� �ظ��ϸ� Y����

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

	_blocks[_poolCountY - 2][_poolCountX - 2]->SetType(MazeBlock::BlockType::END);


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


// ���ձ�(Ȧ����°)
void Maze::CreateMaze()
{
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				continue;
			}

			_blocks[y][x]->SetType(MazeBlock::BlockType::ABLE);


		}
	}
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x%2 ==0 || y%2 == 0)
			{
				continue;
		
			}
		
			//��������
			if (x ==_poolCountX -2 && y==_poolCountY-2)
			{
				continue;
			}

			// ���� ���� �� �շ��ִ�.
			if (x == _poolCountX - 2)
			{
				_blocks[y+1][x]->SetType(MazeBlock::BlockType::ABLE);
				continue;
			}
			// �Ʒ����� �� �շ��ִ�.
			if (y == _poolCountY - 2)
			{
				_blocks[y][x+1]->SetType(MazeBlock::BlockType::ABLE);
				continue;
			}

			//�Ѱ��� ��� ���� ������ Ȥ�� �Ʒ��� �������� �� �ձ�

			const int randValue = rand() % 2;
			if (randValue ==0)
			{ // ������
				_blocks[y][x + 1]->SetType(MazeBlock::BlockType::ABLE);
			}
			else
			{ // �Ʒ���
				_blocks[y+1][x]->SetType(MazeBlock::BlockType::ABLE);
			}

		}
	}



}
