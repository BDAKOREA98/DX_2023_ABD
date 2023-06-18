#include "framework.h"
#include "Timer.h"


Timer* Timer::_instance = nullptr;

Timer::Timer()
{	//1�ʿ� ��� ���� �ϴ��� �� periodFrequency�� ���
	//Query �Լ��� �������� �ü���� �ִ� �Լ���
	QueryPerformanceFrequency((LARGE_INTEGER*) &_periodFrequency);

	// ���α׷��� ������ �� ���ݱ��� CPU������ ���
	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

	// ������ �ѹ� �ϴµ� �ɸ��� �ð� = timeScale
	_timeScale = 1.0 / (double)_periodFrequency;

}

Timer::~Timer()
{
}

void Timer::Update()
{
	//curtime == ������Ʈ �ѹ��� ������
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
		// ������Ʈ�� �ϴٰ� 1�ʰ� ������ onesecCount�� frameCount �� 0 ���� �ٲ���
		// FPS �� frameRate�� �Ǵ°���
		_oneSecCount = 0;
		_frameCount = 0;
	}

	_runTime += _deltaTime;




}