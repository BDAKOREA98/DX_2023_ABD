#include "framework.h"
#include "DunMob.h"

DunMob::DunMob()
{
	_quad = make_shared<Quad>(L"Resource/Texture/chaewon.png", Vector2(230.0f, 145.0f));
	_col = make_shared<RectCollider>(Vector2(250, 150));
	_col->GetTransform()->SetPosition(CENTER);
	_trans = make_shared<Transform>();
	_trans->SetParent(_col->GetTransform());


	
}

DunMob::~DunMob()
{
}

void DunMob::Update()
{
	if (IsActive() == false)
		return;

	_col->Update();
	_trans->Update();
	_quad->Update();
}

void DunMob::Render()
{
	if (IsActive() == false)
		return;

	_col->Render();
	_trans->SetWorldBuffer(0);
	_quad->Render();
}

