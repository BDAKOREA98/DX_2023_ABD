#pragma once

class Effect
{

public:
	Effect(string name, wstring file, Vector2 maxFrame, Vector2 size, float speed = 0.1f, Action::Type type = Action::Type::END);
	Effect(string name, wstring file, string xmlPath, Vector2 size, float speed = 0.1f, Action::Type type = Action::Type::END);
	~Effect();

	void Update();
	void Render();

	void Play(Vector2 pos);
	void End();


	bool _isActive = false;

	
	

private:

	void CreateAction_ByFrame(string name, wstring file, Vector2 maxFrame, Vector2 size, float speed = 0.1f, Action::Type type = Action::Type::END);
	void CreateAction_ByXML(string name, wstring file, string xmlPath, Vector2 size, float speed = 0.1f, Action::Type type = Action::Type::END);

	
	string _name;


	shared_ptr<Sprite> _sprite;
	shared_ptr<Action> _action;
	shared_ptr<Transform> _trans;


	//vector<shared_ptr<Action>> _actions;
	//vector<shared_ptr<Sprite_Clip>> _sprites;
	
};

