#pragma once
class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	virtual  ~ArkanoidScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
private:

	//shared_ptr<Ball> _ball;
	//shared_ptr<Brick> _brick;
	shared_ptr<Stage> _stage;
	//shared_ptr<Bar> _Bar;




	
};

