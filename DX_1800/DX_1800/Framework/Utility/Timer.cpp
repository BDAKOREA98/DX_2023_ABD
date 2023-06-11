#include "framework.h"
#include "Timer.h"


Timer* Timer::_instance = nullptr;

Timer::Timer()
{	//1초에 몇번 진동 하는지 를 periodFrequency에 담기
	//Query 함수는 윈도우즈 운영체제에 있는 함수임
	QueryPerformanceFrequency((LARGE_INTEGER*) &_periodFrequency);

	// 프로그램이 시작할 때 지금까지 CPU진동수 담기
	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

	// 진동을 한번 하는데 걸리는 시간 = timeScale
	_timeScale = 1.0 / (double)_periodFrequency;

}

Timer::~Timer()
{
}

void Timer::Update()
{
	//curtime == 업데이트 한번에 진동수
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);

	_deltaTime = (double)(_curTime - _lastTime) * _timeScale;

	if (_lockFPS != 0)
	{
		while (_deltaTime < (1.0 / _lockFPS))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			_deltaTime = (double)(_curTime - _lastTime) * _timeScale;

		}
	}

	_lastTime = _curTime;
	_frameCount++;
	_oneSecCount += _deltaTime;

	if (_oneSecCount >= 1)
	{
		_frameRate = _frameCount;
		//FPS : frame per scond  
		// 업데이트를 하다가 1초가 지나면 onesecCount와 frameCount 를 0 으로 바꿔줌
		// FPS 가 frameRate가 되는것임
		_oneSecCount = 0;
		_frameCount = 0;
	}

	_runTime += _deltaTime;




}
