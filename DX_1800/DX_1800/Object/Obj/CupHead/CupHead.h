#pragma once
class CupHead
{
public:
	CupHead();
	virtual ~CupHead();

	void Update();
	void Render();
	void PostRender();



private:

	shared_ptr<class player> _player;
	shared_ptr<class CupHeadBG> _background;
	shared_ptr<class Moster> _monster;

	bool IsActive = true;

};

