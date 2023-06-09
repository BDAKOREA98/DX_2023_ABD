#include "framework.h"
#include "EffectManager.h"


EffectManager* EffectManager::_instance = nullptr;


EffectManager::EffectManager()
{
}

EffectManager::~EffectManager()
{
}

void EffectManager::AddEffect(string name, wstring file, Vector2 maxFrame, Vector2 size, float speed, Action::Type type)
{
	if(_effectTable.count(name) != 0)
	{
		return;
	}

	for (int i = 0; i < _poolcount; i++)
	{
		shared_ptr<Effect> effect = make_shared<Effect>(name, file, maxFrame, size, speed, type);
		_effectTable[name].push_back(effect);
	}

}

void EffectManager::AddEffect_(string name, wstring file, wstring xmlPath, Vector2 size, float speed, Action::Type type)
{
	if (_effectTable.count(name) != 0)
	{
		return;
	}

	for (int i = 0; i < _poolcount; i++)
	{
		shared_ptr<Effect> effect = make_shared<Effect>(name, file, xmlPath, size, speed, type);
		_effectTable[name].push_back(effect);
	}
}




void EffectManager::Update()
{

	for (auto pair : _effectTable)
	{
		for (auto effect : pair.second)
		{
			effect->Update();
		}
	}

}

void EffectManager::Render()
{
	for (auto pair : _effectTable)
	{
		for (auto effect : pair.second)
		{
			effect->Render();
		}
	}
}

void EffectManager::Play(string name, Vector2 pos)
{

	if (_effectTable.count(name) == 0)
	{
		return;
	}

	for (auto effect : _effectTable[name])
	{
		if (effect->_isActive == false)
		{
			effect->Play(pos);
			return;
		}
	}

}
