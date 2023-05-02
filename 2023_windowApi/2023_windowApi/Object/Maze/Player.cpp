#include "framework.h"
#include "Player.h"
#include <stack>
#include <queue>

Player::Player(shared_ptr<Maze> maze)
	: _maze(maze)
{
	if (_maze.expired() == false) // 유효하다
	{

		_startPos = _maze.lock()->StartPos();
		_endPos = _maze.lock()->EndPos();
		_maze.lock()->block(_startPos.x, _startPos.y)->SetType(MazeBlock::BlockType::PLAYER);
	}

	BFS();
}

Player::~Player()
{
}

void Player::Update()
{
	_time += 0.4f;
	if (_time > 1.0f)
	{
		_time = 0.0f;
		_pathIndex++;
	}

	if (_pathIndex >= _path.size())
	{
		return;
	}

	Vector2 temp = _path[_pathIndex];
	_maze.lock()->block(temp.x, temp.y)->SetType(MazeBlock::BlockType::PLAYER);


	if (_pathIndex > 1)
	{
		Vector2 temp2 = _path[_pathIndex - 1];
		_maze.lock()->block(temp2.x, temp2.y)->SetType(MazeBlock::BlockType::POSITION);

	}
	
	
}

void Player::RightHand()
{

	Vector2 pos = _startPos;
	_path.push_back(pos);
	Dir curDir = Dir::DIR_UP;

	Vector2 frontPos[4] =
	{
		Vector2 {0, -1}, // UP
		Vector2 {-1, 0}, // LEFT
		Vector2 {0, 1}, // DOWN
		Vector2 {1, 0} // RIGHT
	};

	while (true)
	{
		if (pos == _endPos)
			break;

		int newDir = (curDir - 1 + Dir::DIR_COUNT) % Dir::DIR_COUNT;
		Vector2 oldDirVector = frontPos[curDir]; // 기존방향벡터
		Vector2 newDirVector = frontPos[newDir]; // 새로운방향벡터(시계방향)

		// 현재 바라는방향에서 오른쪽 손을 짚었을 때 갈 수 있는 곳인지 확인
		if (Cango(pos + newDirVector))
		{
			curDir = static_cast<Dir>(newDir);
			pos += newDirVector;
			_path.push_back(pos);
		}

		// 현재 바라보는 방향으로 전진할 수 있는지 확인
		else if (Cango(pos + oldDirVector))
		{
			pos += oldDirVector;
			_path.push_back(pos);
		}

		// 오른쪽 손 짚어도 못가고, 앞으로도 못가는 상황 반시계로 회전
		else
		{
			curDir = static_cast<Dir>((curDir + 1 + Dir::DIR_COUNT) % Dir::DIR_COUNT);
		}
	}

	stack<Vector2> s;

	for (int i = 0; i < _path.size()-1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
		{
			s.pop();
		}
		else
			s.push(_path[i]);
	}

	s.push(_endPos);
	_path.clear();
	while (true)
	{
		if(s.empty())
		{
			break;
		}
		_path.push_back(s.top());
		s.pop();
	}

	std::reverse(_path.begin(), _path.end());

	return;
}
void Player::BFS()
{
	Vector2 poolCount = _maze.lock()->PoolCount();
	int poolCountX = (int)poolCount.x;
	int poolCountY = (int)poolCount.y;
	_discovered = vector<vector<bool>>(poolCountY, vector<bool>(poolCountX, false));
	_parent = vector<vector<Vector2>>(poolCountY, vector<Vector2>(poolCountX, Vector2(-1, -1)));

	queue<Vector2> q;
	q.push(_startPos);
	_discovered[_startPos.y][_startPos.x] = true;
	_parent[_startPos.y][_startPos.x] = _startPos;
	//_visited.push_back(_startPos);

	Vector2 frontPos[8] =
	{
		
		
		Vector2 {1,1}, // DOWN RIGHT
		Vector2 {0, 1}, // DOWN
		Vector2 {1, 0}, // RIGHT
		Vector2 {0, -1}, // UP
		Vector2 {1,-1}, ///  UP RIGHT
		Vector2 {-1, 0}, // LEFT
		Vector2 {-1,1}, // DOWN LEFT
		Vector2 {-1,-1} //UP LEFT

		
	
		
	};

	while (true)
	{
		if (q.empty())
		{
			break;
		}
		Vector2 here = q.front();
		q.pop();

		if (here == _endPos)
			break;
		for (int i = 0; i < 8; i++)
		{
			Vector2 there = here + frontPos[i];

			if (Cango(there) == false)
			{
				continue;
			}

			if (_discovered[there.y][there.x] == true)
			{
				continue;
			}
			q.push(there);
			_discovered[there.y][there.x] = true;
			_parent[there.y][there.x] = here;

			
			_maze.lock()->block(there.x, there.y)->SetType(MazeBlock::BlockType::PLAYER);

		}

	}

	Vector2 temp = _endPos;
	_path.push_back(temp);
	while (true)
	{
		

		temp = _parent[temp.y][temp.x];
		_path.push_back(temp);

		if (temp == _parent[temp.y][temp.x])
			break;
	}
	std::reverse(_path.begin(), _path.end());
}
bool Player::Cango(Vector2 pos)
{

	MazeBlock::BlockType type = _maze.lock()->block(pos.x, pos.y)->GetType();
	if (type == MazeBlock::BlockType::DISABLE)
		return false;
	if (type == MazeBlock::BlockType::NONE)
		return false;

	return true;
}
