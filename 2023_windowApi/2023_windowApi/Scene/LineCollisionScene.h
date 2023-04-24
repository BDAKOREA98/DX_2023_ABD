#pragma once
class LineCollisionScene : public Scene
{
public:
	LineCollisionScene();
	virtual ~LineCollisionScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	bool isIntersect(shared_ptr<Line> s1, shared_ptr<Line> s2);

	Vector2 getIntersection(shared_ptr<Line> s1, shared_ptr<Line> s2);

private:
	shared_ptr<Line> _line1;
	shared_ptr<Line> _line2;
};

