#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	virtual ~TutorialScene();


	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

	

private:
	

	shared_ptr<Quad> _qurd;



	
};

