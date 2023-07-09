#include "framework.h"
#include "Effect.h"
#include "../../Types.h"
Effect::Effect(string name, wstring file, Vector2 maxFrame, Vector2 size, float speed, Action::Type type)
	:_name(name)
{
	_trans = make_shared<Transform>();
	CreateAction_ByFrame(name, file, maxFrame, size, speed, type);
	End();

}

Effect::Effect(string name, wstring file, string xmlPath, Vector2 size, float speed, Action::Type type)
	: _name(name)
{
	_trans = make_shared<Transform>();
	CreateAction_ByXML(name, file, xmlPath, size, speed, type);
	End();
}


Effect::~Effect()
{
}

void Effect::Update()
{
	if (_isActive == false)
		return;

	_trans->Update();
	_action->Update();
	_sprite->SetCurClip(_action->GetCurClip());
	_sprite->Update();

	/*if (!_sprites.empty())
	{
		_sprites[0]->Update();
		_actions[0]->Update();
	}*/

}

void Effect::Render()
{
	if (_isActive == false)
		return;

	_trans->SetWorldBuffer(0);
	_sprite->Render();
}

void Effect::Play(Vector2 pos)
{

	_isActive = true;

	_trans->SetPosition(pos);

	_action->Play();


	//if (!_actions.empty())
	//{
	//	_actions[0]->Play();
	//}


}

void Effect::End()
{

	_isActive = false;
	_trans->SetPosition(Vector2(-10000.0f, -10000.0f));

}

void Effect::CreateAction_ByFrame(string name, wstring file, Vector2 maxFrame, Vector2 size, float speed, Action::Type type)
{
	// Action을 만드는 단계 (Frame별로 나뉘어져있기에)

	_sprite = make_shared<Sprite_Frame>(file, maxFrame, size);
	shared_ptr<SRV> srv = ADD_SRV(file);

	Vector2 clipSize = _sprite->GetImageSize();
	
	clipSize.x /= maxFrame.x;
	clipSize.y /= maxFrame.y;

	vector<Action::Clip> clips;

	for (int y = 0; y < maxFrame.y; y++)
	{
		for (int x = 0; x < maxFrame.x; x++)
		{
			Action::Clip clip = Action::Clip(x * clipSize.x, y * clipSize.y, clipSize.x, clipSize.y, srv);
			clips.push_back(clip);
		}

	}

	_action = make_shared<Action>(clips, name, type, speed);
	_action->SetEndEvent(std::bind(&Effect::End, this));


}

void Effect::CreateAction_ByXML(string name, wstring file, string xmlPath, Vector2 size, float speed, Action::Type type)
{

}
