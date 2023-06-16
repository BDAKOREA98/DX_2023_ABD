#include "framework.h"
#include "DunBullet.h"

DunBullet::DunBullet()
{
	_quad = make_shared<Quad>(L"Resource/Texture/Bullet.png");
	_quadtrans = make_shared<Transform>();
	_quadtrans->SetScale(Vector2(0.05f, 0.05f));
	//_quadtrans->SetPosition(Vector2(-100.0f, -100.0f));

	_col = make_shared<CircleCollider>(200.0f);
	_col->GetTransform()->SetParent(_quadtrans);
}

DunBullet::~DunBullet()
{
}

void DunBullet::Update()
{
	if (_isActive == false)
		return;

	if (_pos.x > WIN_WIDTH || _pos.x < 0.0f)
		_isActive = false;
	if (_pos.y > WIN_HEIGHT || _pos.y < 0.0f)
		_isActive = false;

	_pos += _dir * _speed;
	_quadtrans->SetPosition(_pos);
	_quadtrans->SetAngle(_dir.Angle());
	_quad->Update();
	_quadtrans->Update();
	_col->Update();
}

void DunBullet::Render()
{
	if (_isActive == false)
		return;

	_quadtrans->SetWorldBuffer(0);
	_quad->Render();
	_col->Render();
}
