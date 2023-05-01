#pragma once
class MazeScene : public Scene
{
public:
	MazeScene();
	virtual ~MazeScene();

	virtual void Update();
	virtual void Render(HDC hdc);

private:

	shared_ptr<Maze> _maze;
	shared_ptr<Player> _player;

};

