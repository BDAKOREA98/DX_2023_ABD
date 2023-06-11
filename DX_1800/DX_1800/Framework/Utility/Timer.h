#pragma once
class Timer
{
private:
	Timer();
	~Timer();

public:
	static void Create()
	{
		if (_instance == nullptr)
		{
			_instance = new Timer();
		}
	}
	static void Delete()
	{
		if (_instance != nullptr)
		{
			delete _instance;
		}
	}
	static Timer* GetInstance()
	{
		if (_instance != nullptr)
		{
			return _instance;
		}
		return nullptr;
	}

	void Update();

	int GetFPS() { return _frameRate; }
	double GetDeltaTime() { return _deltaTime; }
	double GetRunTime() { return _runTime; }

private:
	static Timer* _instance;


	double _timeScale = 0.0f;  // 시간의 크기?? 비율 등등 2로 설정하면 2배빠르게감
	double _deltaTime = 0.0f;  // 한번 업데이트에 걸리는 시간

	unsigned __int64  _curTime = 0;
	unsigned __int64  _lastTime = 0;
	unsigned __int64  _periodFrequency = 0; // 주파수

	unsigned int _frameRate = 0; // FPS
	unsigned int _frameCount = 0; //

	double _oneSecCount = 0.0f;
	double _runTime = 0.0f; // 총 경과 된 시간
	double _lockFPS = 0.0f;


};

