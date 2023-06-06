#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_rectCollider = make_shared<RectCollider>(Vector2(100, 80));
	_rectCollider->GetTranform()->SetPosition(CENTER);

	_CircleCollider = make_shared<CircleCollider>(50.0f);
	_CircleCollider->GetTranform()->SetPosition(CENTER);
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	_rectCollider->GetTranform()->SetPosition(MOUSE_POS);
	_rectCollider->Update();

	_CircleCollider->Update();

}

void ColliderScene::Render()
{
	_rectCollider->Render();
	_CircleCollider->Render();
}
