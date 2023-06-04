#include "framework.h"
#include "SolarSystem.h"

SolarSystem::SolarSystem()
{
	_sun = make_shared<Planet>(L"sun");
	_sun->SetScale(Vector2(0.3f, 0.3f));
	_sun->SetPosition(CENTER);

	_earth = make_shared<Planet>(L"earth");
	_earth->SetScale(Vector2(0.3f, 0.3f));
	_earth->SetRotation(0.0002f);
	// ������ �¾��� ���ӵǾ��ֱ⿡ �¾��� ������ �� �������� ���������� �������� �̵��ϰ� �ȴ�.
	
	_earth->SetPosition(Vector2(600.0f, 600.0f));


	_moon = make_shared<Planet>(L"moon");
	_moon->SetScale(Vector2 (0.5f, 0.5f));
	_moon->SetRotation(0.0003f);
	_moon->SetPosition(Vector2(600.0f, 300.0f));

	
	
	_earth->SetParent(_sun->GetOrbit());
	_moon->SetParent(_earth->GetTransform());

	// Alpha or Additiveó��
	// Alpha == �ؽ��� ������ ���� ������
	// Additive == �ڿ��ִ� ���� ȥ���ؼ� ������
	_BlendState = make_shared<BlendState>();
	_BlendState->Alpha();
}

SolarSystem::~SolarSystem()
{
}

void SolarSystem::Update()
{
	
	_BlendState->SetState();
	_sun->SetPosition(mousePos);


	_sun->Update();
	_earth->Update();
	_moon->Update();
}

void SolarSystem::Render()
{
	_sun->Render();
	_earth->Render();
	_moon->Render();
	

}
