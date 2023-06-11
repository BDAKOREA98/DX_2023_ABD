#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_rect = make_shared<RectCollider>(Vector2 (50.0f,150.0f));
	_rect->GetTransform()->SetPosition(CENTER);
	_rectcol = make_shared<RectCollider>(Vector2 (50.0f,50.0f));
	_rectcol->GetTransform()->SetPosition(CENTER + Vector2(-100.0f, 0.0f));
	
	_Circle = make_shared<CircleCollider>(50.0f);
	_Circle->GetTransform()->SetPosition(CENTER);
	_Circlecol = make_shared<CircleCollider>(50.0f);
	_Circlecol->GetTransform()->SetPosition(CENTER + Vector2(100.0f, 0.0f));
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	


	if (_rectcol->IsOBB(_rect))
	{
		_rect->SetRed();
		_rectcol->SetRed();
	}
	else
	{
		_rect->SetGreen();
		_rectcol->SetGreen();
	}


	_rectcol->GetTransform()->SetPosition(_pos);
	_rectcol->GetTransform()->SetScale(_scale);
	_rectcol->GetTransform()->SetAngle(_angle);


	_rectcol->Update();
	_Circlecol->Update();
	_rect->Update();
	_Circle->Update();

}

void ColliderScene::Render()
{
	_rect->Render();
	_Circle->Render();
	_rectcol->Render();
	_Circlecol->Render();
}

void ColliderScene::PostRender()
{
	ImGui::SliderFloat2("Pos", (float*)&_pos, 0, 1280, "%.0f");
	ImGui::SliderFloat2("Scale", (float*)&_scale, 0, 3, "%.1f");
	ImGui::SliderFloat2("Angle", &_angle, 0, 360, "%.1f");


}
