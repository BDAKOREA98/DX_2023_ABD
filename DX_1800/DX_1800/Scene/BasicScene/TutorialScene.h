#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	virtual ~TutorialScene();


	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

	

private:
	
	float _x = 0.0f;
	float _y = 0.0f;

	shared_ptr<Qurd> _qurd;

	shared_ptr<MatrixBuffer> _world;
	shared_ptr<MatrixBuffer> _view;
	shared_ptr<MatrixBuffer> _proj;

};

