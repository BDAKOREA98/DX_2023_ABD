#pragma once
class SpriteScene : public Scene
{

public:
	SpriteScene();
	~SpriteScene();
	
	virtual void Update() override;

	virtual void Render() override;
	virtual void PostRender() override;

private:


	shared_ptr<Transform> _trans;
	shared_ptr<Sprite> _sprite;

	Vector2 _curFrame;
};

