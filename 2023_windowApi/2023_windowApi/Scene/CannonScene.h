#pragma once

class CannonScene : public Scene
{
public:
	CannonScene();
	virtual ~CannonScene();

	virtual void Update() ;
	virtual void Render(HDC hdc) ;



private:

	shared_ptr<Cannon> _cannon;

};

