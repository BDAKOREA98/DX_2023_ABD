#include "framework.h"
#include "Planet.h"

Planet::Planet(wstring name)
{
	wstring path = L"Resource/Texture/" + name + L".png";

	_quad = make_shared<Quad>(path);
	_orbit = make_shared<Transform>();
	_trans = make_shared<Transform>();

}

Planet::~Planet()
{
}

void Planet::Update()
{
	_trans->AddAngle(_rotationSpeed);

	_orbit->AddAngle(_rotationSpeed * 1.5f);
	
	_orbit->Update();
	_trans->Update();
	_quad->Update();
}

void Planet::Render()
{
	_quad->Render();
	_trans->SetWorldBuffer(0);
	_orbit->SetWorldBuffer(0);
}

void Planet::SetScale(Vector2 scale)
{ 
	_trans->SetScale(scale);
	_orbit->SetScale(scale);
}

void Planet::SetPosition(Vector2 pos)
{
	
	_trans->SetPosition(pos);
	 _orbit->SetPosition(pos);
}

void Planet::SetParent(shared_ptr<Transform> trans)
{
	_trans->SetParent(trans);
	 _orbit->SetParent(trans);
}
