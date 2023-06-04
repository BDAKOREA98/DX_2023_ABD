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
	// 지구는 태양의 종속되어있기에 태양의 스케일 이 곱해져서 넣은값보다 작은값이 이동하게 된다.
	
	_earth->SetPosition(Vector2(600.0f, 600.0f));


	_moon = make_shared<Planet>(L"moon");
	_moon->SetScale(Vector2 (0.5f, 0.5f));
	_moon->SetRotation(0.0003f);
	_moon->SetPosition(Vector2(600.0f, 300.0f));

	
	
	_earth->SetParent(_sun->GetOrbit());
	_moon->SetParent(_earth->GetTransform());

	// Alpha or Additive처리
	// Alpha == 텍스쳐 본인의 색을 가져옴
	// Additive == 뒤에있는 색을 혼합해서 가져옴
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
