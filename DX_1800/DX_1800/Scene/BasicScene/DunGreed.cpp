#include "framework.h"
#include "DunGreed.h"

DunGreed::DunGreed()
{
	_player = make_shared<DunPlayer>();

	_chaewon = make_shared<Planet>(L"chaewon");
	_chaewon->SetPosition(CENTER);
	_chaewon->SetScale(Vector2(0.3f, 0.3f));

}

DunGreed::~DunGreed()
{

}

void DunGreed::Update()
{
	_player->Update();
	_chaewon->SetPosition(mousePos);
	_chaewon->Update();
}

void DunGreed::Render()
{
	_player->Render();
	_chaewon->Render();
}
