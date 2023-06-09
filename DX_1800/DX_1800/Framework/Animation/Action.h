#pragma once
#include "../../Types.h"
class Action
{
public:

	struct Clip
	{
		Vector2 startPos;
		Vector2 size;
		weak_ptr<SRV> srv;

		Clip(float x, float y, float w, float h, shared_ptr<SRV> srv)
			: startPos(x, y)
			, size(w, h)
			, srv(srv)
		{

		}
		
	};

	enum Type
	{
		END,
		LOOP,
		PINFPONG
	};

	Action(vector<Clip> clips, string name = "", Type type = Type::LOOP, float speed = 0.1f);
	~Action();

		void Update();

		void Play();
		void Pause();
		void Stop();
		void Reset();
	
		Clip GetCurClip() { return _clips[_curClipIndex]; }

		void SetEndEvent(CallBack event_) { _endEvent = event_; }
		void SetNumEvent(CallBack2 event_) { _eventNum = event_; }

private:

	string _name;
	vector<Clip> _clips;

	Type _repeatType;
	bool _isPlay = false;

	UINT _curClipIndex = 0;

	float _time = 0.0f;
	float _speed = 0.0f;

	bool _isReverse = false; 


	// 리스너 패턴, 옵저버패턴
	// ->Delogate
	CallBack _endEvent = nullptr;
	CallBack2 _eventNum = nullptr;

};

