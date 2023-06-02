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
	

	shared_ptr<Qurd> _qurd;

	

	shared_ptr<Transform> _transform;

	shared_ptr<MatrixBuffer> _world;
	shared_ptr<MatrixBuffer> _view;
	shared_ptr<MatrixBuffer> _proj;

};

