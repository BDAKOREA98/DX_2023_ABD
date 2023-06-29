#include "framework.h"
#include "CupHead.h"
#include "CupHeadBG.h"
#include "player.h"
#include "Moster.h"

CupHead::CupHead()
{
	_background = make_shared<CupHeadBG>();
	_player = make_shared<player>();
	_monster = make_shared<Moster>();
}

CupHead::~CupHead()
{
}

void CupHead::Update()
{


	_background->Update();
	_player->Update();
	_monster->Update();

	
	if (_background->GetCollider()->Block(_player->GetCol()) && _player->GetOldState() == _player->JUMP)
	{
		_player->SetAction(_player->State::IDLE);
		_player->_isFalling = false;
	}
	
	

}

void CupHead::Render()
{
	_background->Render();
	_player->Render();
	_monster->Render();
}

void CupHead::PostRender()
{
	//_player->PostRender();
}
