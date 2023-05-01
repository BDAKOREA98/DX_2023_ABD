#include "framework.h"
#include "Stage.h"

Stage::Stage()
{
	_stage = make_shared<RectCollider>(CENTER, Vector2(500, 550) );
	HBRUSH _hbrush = CreateSolidBrush(GREEN);
	


}

Stage::~Stage()
{
}

void Stage::Update()
{
	_stage->Update();
}

void Stage::Render(HDC hdc)
{
	_stage->Render(hdc);

	
}
