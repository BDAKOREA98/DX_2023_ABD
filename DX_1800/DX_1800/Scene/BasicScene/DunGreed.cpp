#include "framework.h"
#include "DunGreed.h"

DunGreed::DunGreed()
{
	_player = make_shared<DunPlayer>();
	_playertrans = make_shared<Transform>();

	
	

	
	
	

}

DunGreed::~DunGreed()
{

}

void DunGreed::Update()
{
	
	

	
	_player->Update();
	_playertrans->Update();
	
	
	

	
}

void DunGreed::Render()
{
	_playertrans->SetWorldBuffer(0);
	_player->Render();
	
	
}
