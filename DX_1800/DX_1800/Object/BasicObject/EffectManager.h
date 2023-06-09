#pragma once
class EffectManager
{

private:
	EffectManager();
	~EffectManager();


public:

	static void Create()
	{
		if (_instance == nullptr)
		{
			_instance = new EffectManager();
		}
	}

	static void Delete()
	{
		if (_instance != nullptr)
		{
			delete _instance;
		}
	}

	static EffectManager* GetInstance()
	{
		if (_instance != nullptr)
		{
			return _instance;
		}

		return nullptr;
	}
	
	
	void AddEffect(string name, wstring file, Vector2 maxFrame, Vector2 size, float speed = 0.03f
		, Action::Type type = Action::Type::END);

	void AddEffect_(string name, wstring file, wstring xmlPath, Vector2 size, float speed = 0.1f, Action::Type type = Action::Type::END);

	void Update();
	void Render();

	
	void Play(string name, Vector2 pos);
	


private:


	UINT _poolcount = 30;

	static EffectManager*  _instance;

	unordered_map<string, vector<shared_ptr<Effect>>> _effectTable;


};

