#include "framework.h"
#include "DunPlayer.h"

DunPlayer::DunPlayer()
{
	_player = make_shared<Quad>(L"Resource/Texture/Player.png");
	_bowTrans = make_shared<Transform>();
	_bow = make_shared<DunBow>(L"Resource/Texture/bow.png");
	
	_bulletTrans = make_shared<Transform>();
	

	for (int i = 0; i < 10; i++)
	{
		shared_ptr<DunBullet> bullet = make_shared<DunBullet>();
		bullet->SetActive(false);
		_bullets.push_back(bullet);
	}

	_player->GetTransform()->SetPosition(Vector2(80.0f, 80.0f));
	_bowTrans->SetParent(_player->GetTransform());

	_bow->GetTransform()->SetAngle(-PI * 0.75f);
	_bow->GetTransform()->SetPosition(Vector2(80.0f, 0.0f));
	_bow->GetTransform()->SetParent(_bowTrans);

	_bulletTrans->SetParent(_bowTrans);
	_bulletTrans->SetPosition(Vector2(120.0f, 0.0f));
}

DunPlayer::~DunPlayer()
{
}

void DunPlayer::Update()
{
	_bowTrans->SetAngle((MOUSE_POS - _bowTrans->GetWorldPos()).Angle());

	Fire();
	Move();
	_player->Update();
	_bowTrans->Update();
	_bow->Update();
	_bulletTrans->Update();

	for (auto bullet : _bullets)
		bullet->Update();
}

void DunPlayer::Render()
{
	for (auto bullet : _bullets)
		bullet->Render();
	_bow->Render();
	_player->Render();
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
		_player->GetTransform()->AddVector2(Vector2(0.2f, 0.0f));
	}
	if (KEY_PRESS('A'))
	{
		_player->GetTransform()->AddVector2(Vector2(-0.2f, 0.0f));
	}
	if (KEY_PRESS('W'))
	{
		_player->GetTransform()->AddVector2(Vector2(0.0f, 0.2f));
	}
	if (KEY_PRESS('S'))
	{
		_player->GetTransform()->AddVector2(Vector2(0.0f, -0.2f));
	}



}
