#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	virtual ~TutorialScene();


	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	

private:
	

	shared_ptr<Quad> _qurd;
	shared_ptr<Transform> _trans;


	shared_ptr<FilterBuffer> _filterBuffer;


	shared_ptr<Effect> _effect;
	
};

