#include "framework.h"
#include "player.h"
#include "Bullet.h"
#include "CupHeadBG.h"

player::player()
{
	_col = make_shared<CircleCollider>(50);
	_trans = make_shared<Transform>();

	CreateAction("Idle");
	CreateAction("Run");
	CreateAction("Jump");
	CreateAction("AimStraightShot", 0.1f, Action::END);

	_col->GetTransform()->SetPosition(CENTER);
	_trans->SetParent(_col->GetTransform());
	_trans->SetPosition(Vector2(0, 20));

	_actions[State::IDLE]->Play();
	_actions[State::RUN]->Play();

	_sprites[0]->SetLeft();
	_sprites[1]->SetLeft();

	_background = make_shared<CupHeadBG>();

	for (int i = 0; i < 30; i++)
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		_bullets.push_back(bullet);
	}
	

}

player::~player()
{
}

void player::Update()
{
	_col->Update();
	_trans->Update();
	for (auto bullet : _bullets)
	{
		bullet->Update();
	}
	Input();
	Jump();
	

	_actions[_state]->Update();

	_sprites[_state]->SetCurClip(_actions[_state]->GetCurClip());
	_sprites[_state]->Update();

	Shoot();
	_background->Update();


}

void player::Render()
{
	_background->Render();

	_trans->SetWorldBuffer(0);
	_sprites[_state]->Render();
	_col->Render();


	for (auto bullet : _bullets)
	{
		bullet->Render();
	}
}

void player::PostRender()
{
	ImGui::SliderInt("State", (int*)&_state, 0, 1);
}

void player::CreateAction(string name, float speed, Action::Type type, CallBack callback)
{
	// srv만드는 작업
	// IDLE, RUN
	wstring wName = wstring(name.begin(), name.end());
	wstring srvPath = L"Resource/CupHead/Charactor/" + wName + L".png";
	shared_ptr<SRV> srv = ADD_SRV(wName);
	
	// xmldocument 만들기
	string xmlPath = "Resource/CupHead/Charactor/" + name + ".xml";
	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	document->LoadFile(xmlPath.c_str());

	tinyxml2::XMLElement* textureAtlas = document->FirstChildElement();
	tinyxml2::XMLElement* row = textureAtlas->FirstChildElement();

	vector<Action::Clip> clips;

	float averageW = 0;
	float averageH = 0;
	int count = 0;
	while (true)
	{
		if (row == nullptr)
		{
			break;
		}
		// row에서 필요한 값을 인트형 변환 후 클립에 담기
		int x = row->FindAttribute("x")->IntValue();
		int y = row->FindAttribute("y")->IntValue();
		int w = row->FindAttribute("w")->IntValue();
		int h = row->FindAttribute("h")->IntValue();
		
		averageW += w;
		averageH += h;
		count++;


		Action::Clip clip = Action::Clip(x, y, w, h, srv);
		clips.push_back(clip);
		// 다음 자식으로 넘어가기
		row = row->NextSiblingElement();
	}

	shared_ptr<Action> action = make_shared<Action>(clips, name, type, speed);
	action->SetEndEvent(callback);

	_actions.push_back(action);

	shared_ptr<Sprite_Clip> sprite = make_shared<Sprite_Clip>(srvPath, Vector2(averageW/count, averageH/count));
	_sprites.push_back(sprite);

}

void player::Input()
{

	if (KEY_PRESS('A'))
	{
		_col->GetTransform()->AddVector2(LEFT_VECTOR * DELTA_TIME * _speed);
		SetLEFT();
		SetAction(State::RUN);
	}
	else if (KEY_UP('A'))
	{
		SetAction(State::IDLE);
	}
	if (KEY_PRESS('D'))
	{
		_col->GetTransform()->AddVector2(RIGHT_VECTOR * DELTA_TIME * _speed);
		SetRIGHT();
		SetAction(State::RUN);
	}
	else if (KEY_UP('D'))
	{
		SetAction(State::IDLE);
	}

	
	

}

void player::Shoot()
{
	if (KEY_DOWN(VK_LBUTTON))
	{
		shared_ptr<Bullet> bullet = SetBullet();
		
		
		if (bullet == nullptr)
			return;
		
		bullet->SetActiv(true);
		bullet->SetPosition(_col->GetWorldPos());
		bullet->SetDirtection(MOUSE_POS - _col->GetWorldPos());


	}
	
	

}

void player::SetAction(State state)
{

	if (_state == state)
	{
		return;
	}
	_actions[_state]->Reset();
	_actions[_state]->Pause();
	_state = state;
	_actions[_state]->Play();
}
shared_ptr<Bullet> player::SetBullet()
{
	for (auto bullet : _bullets)
	{
		if (bullet->GetActiv() == false)
			return bullet;

	}
	return nullptr;
}

void player::Jump()
{
	
	if (_isFalling == false)
	{	
		_jumpPower -= GRAVITY ;

		if (_jumpPower < -_maxFalling)
			_jumpPower = -_maxFalling;

		_col->GetTransform()->AddVector2(Vector2(0.0f, _jumpPower * DELTA_TIME));
		_background->GetCollider()->Block(_col);
	
	}

	if (KEY_DOWN(VK_SPACE))
	{

		_jumpPower = 1500.0f;
		SetAction(State::JUMP);
		_isFalling = true;
	}
	
}