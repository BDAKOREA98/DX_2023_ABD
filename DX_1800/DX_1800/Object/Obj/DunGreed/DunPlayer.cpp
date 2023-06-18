#include "framework.h"
#include "DunPlayer.h"


DunPlayer::DunPlayer()
{
	_player = make_shared<Quad>(L"Resource/Texture/Player.png");
	_playertrans = make_shared<Transform>();
	_playertrans->SetPosition(Vector2(100.0f, 100.0f));

	
	_bowslot = make_shared<Transform>();
	_bowslot->SetParent(_playertrans);
	_bowslot->SetPosition(Vector2(0.0f, 0.0f));
	
	_bowTrans = make_shared<Transform>();
	_bowTrans->SetParent(_bowslot);
	_bowTrans->SetPosition(Vector2(100.0f, 0.0f));
	_bowTrans->SetAngle(-PI* 0.75);
	
	_bow = make_shared<DunBow>(L"Resource/Texture/bow.png");
	
	_bulletTrans = make_shared<Transform>();
	_bulletTrans->SetParent(_bowTrans);
		
	
	for (int i = 0; i < 30; i++)
	{
		shared_ptr<DunBullet> bullet = make_shared<DunBullet>();
		bullet->SetActive(false);
		bullet->SetPos(_bowslot->GetPos());
		_bullets.push_back(bullet);
	}

	_mob = make_shared<DunMob>();
	
}

DunPlayer::~DunPlayer()
{
}

void DunPlayer::Update()
{

	Move();


	for (auto bullet : _bullets)
	{
		
		bullet->Update();
	}

	
	Attack();

	Fire();
	_bowslot->SetAngle((MOUSE_POS - _bowTrans->GetWorldPos()).Angle());
	_bowslot->Update();
	_bowTrans->Update();
	_bow->Update();
	_bulletTrans->Update();
	_mob->Update();

	_player->Update();
	_playertrans->Update();
	
}

void DunPlayer::Render()
{
	_playertrans->SetWorldBuffer(0);
	_player->Render();
	_bowTrans->SetWorldBuffer(0);
	_bow->Render();
	_mob->Render();
	_bulletTrans->SetWorldBuffer(0);
	for (auto bullet : _bullets)
	{
		bullet->Render();
	}


}

void DunPlayer::Fire()
{
	
	if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000))
	{
		_spacePress = true;
		_spaceUp = false;
	}
	else
	{
		_spaceUp = true;
	}

	if (_spacePress == true && _spaceUp == true)
	{
		shared_ptr<DunBullet> bullet = SetBullet();

		if (bullet == nullptr)
			return;

		bullet->SetPos(_bulletTrans->GetWorldPos());
		bullet->SetDir((MOUSE_POS - _bowTrans->GetWorldPos() + Vector2(0.0f, -36.0f)));
		bullet->SetActive(true);

		_spacePress = false;
		_spaceUp = false;
	}

}

shared_ptr<DunBullet> DunPlayer::SetBullet()
{
	for (auto bullet : _bullets)
	{
		if (bullet->IsActive() == false)
			return bullet;

	}
	return nullptr;
}

void DunPlayer::Move()
{
	if (KEY_PRESS('D'))
	{
		_playertrans->AddVector2(Vector2(0.2f, 0.0f));
	}
	if (KEY_PRESS('A'))
	{
		_playertrans->AddVector2(Vector2(-0.2f, 0.0f));
	}
	if (KEY_PRESS('W'))
	{
		_playertrans->AddVector2(Vector2(0.0f, 0.2f));
	}
	if (KEY_PRESS('S'))
	{
		_playertrans->AddVector2(Vector2(0.0f, -0.2f));
	}



}

void DunPlayer::Attack()
{
	if (_mob->IsActive() == true)
	{
		for (auto bullet : _bullets)
		{
			if (bullet->IsActive() == false)
			{
				continue;
			}
			if (bullet->GetCol()->IsCollision(_mob->GetCollider()))
			{
				_mob->TakeDamage(1);
				bullet->_isActive = false;

			}
		}
	}
}
