#pragma once
class Action;
class Sprite : public Quad
{
protected:

	Sprite(wstring path);
	Sprite(wstring path, Vector2 size);
	virtual ~Sprite();

public:
	virtual void Update() override;
	virtual void Render() override;

	virtual void CreateVertices() override;
	virtual void CreateData(wstring path) override;

	

protected:

	shared_ptr<ActionBuffer> _actionBuffer;

};

