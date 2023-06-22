#include "framework.h"
#include "CupHeadBG.h"

CupHeadBG::CupHeadBG()
{
	_quad = make_shared<Quad>(L"Resource/CupHead/backGround/BackGround/clown_bg_track.png");
	_col = make_shared<RectCollider>(_quad->GetImageSize());

	_col->GetTransform()->SetPosition(CENTER + Vector2(0.0f,-200.0f));
	_transform = make_shared<Transform>();
	_transform->SetParent(_col->GetTransform());
	_transform->SetPosition(Vector2(0.0f, 70.0f));
}

CupHeadBG::~CupHeadBG()
{
}

void CupHeadBG::Update()
{
	_col->Update();
	_transform->Update();
	_quad->Update();
}

void CupHeadBG::Render()
{
	_transform->SetWorldBuffer(0);
	_quad->Render();

	_col->Render();
}
