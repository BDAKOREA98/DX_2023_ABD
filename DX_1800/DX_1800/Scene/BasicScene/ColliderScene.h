#pragma once
class ColliderScene : public Scene
{
public:
	ColliderScene();
	virtual ~ColliderScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;
private:
	shared_ptr<RectCollider> _rect;
	shared_ptr<RectCollider> _rectcol;

	shared_ptr<CircleCollider> _Circle;
	//shared_ptr<CircleCollider> _Circlecol;

	Vector2 _pos = CENTER;
	Vector2 _scale = { 1.0f, 1.0f };
	float _angle = 0.0f;


};

