#pragma once
class Action;
class SpriteScene : public Scene
{

public:
	SpriteScene();
	~SpriteScene();
	
	virtual void Update() override;

	virtual void Render() override;
	virtual void PostRender() override;

	void CreateAction();

	// ��� �Լ� ȣ���� ���ؼ� ��ü�� �ʿ���
	void EndEvent() { _event = "END!!!!!"; }

	void EndEventNum(int num) { _eventNumber = num; }

private:

	string _event = "Not End";
	int _eventNumber = 0;

	shared_ptr<Transform> _trans;
	shared_ptr<Sprite_Clip> _sprite;
	shared_ptr<Action> _action;

	Vector2 _curFrame;
};

