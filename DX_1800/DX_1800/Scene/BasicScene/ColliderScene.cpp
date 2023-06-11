#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_rect = make_shared<RectCollider>(Vector2 (50.0f,150.0f));
	_rect->GetTransform()->SetPosition(CENTER);
	_rectcol = make_shared<RectCollider>(Vector2 (100.0f,100.0f));
	_rectcol->GetTransform()->SetPosition(CENTER);
	
	_Circle = make_shared<CircleCollider>(50.0f);
	_Circle->GetTransform()->SetPosition(CENTER);
	//_Circlecol = make_shared<CircleCollider>(50.0f);
	//_Circlecol->GetTransform()->SetPosition(CENTER);
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	
	if (KEY_PRESS('W'))
	{
		_rectcol->GetTransform()->AddVector2(UP_VECTOR * DELTA_TIME * 500.0f);
	}
	if (KEY_PRESS('S'))
	{
		_rectcol->GetTransform()->AddVector2(DOWN_VECTOR * DELTA_TIME * 500.0f);
	}
	if (KEY_PRESS('D'))
	{
		_rectcol->GetTransform()->AddVector2(RIGHT_VECTOR * DELTA_TIME * 500.0f);
	}
	if (KEY_PRESS('A'))
	{
		_rectcol->GetTransform()->AddVector2(LEFT_VECTOR * DELTA_TIME * 500.0f);
	}


	_rectcol->Update();
	//_Circlecol->Update();
	_rect->Update();
	_Circle->Update();

	if (_rectcol->IsOBB(_Circle) || _rectcol->IsOBB(_rect))
	{
		_Circle->SetRed();
		_rectcol->SetRed();
		_rect->SetBlue();
	}
	else
	{
		_Circle->SetGreen();
		_rectcol->SetGreen();
		_rect->SetGreen();
	}


	//_rectcol->GetTransform()->SetPosition(_pos);
	_rectcol->GetTransform()->SetScale(_scale);
	_rectcol->GetTransform()->SetAngle(_angle);




}

void ColliderScene::Render()
{
	_rect->Render();
	_Circle->Render();
	_rectcol->Render();
	//_Circlecol->Render();
}

void ColliderScene::PostRender()
{
	//ImGui::SliderFloat2("Pos", (float*)&_pos, 0, WIN_WIDTH, "%.0f");
	//ImGui::SliderFloat2("Scale", (float*)&_scale, 0, 3, "%.1f");
	//ImGui::SliderFloat2("Angle", &_angle, 0, 2*PI, "%.3f");
	//

}
