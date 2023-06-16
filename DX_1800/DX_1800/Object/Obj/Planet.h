#pragma once
class Planet
{
public:	
	Planet(wstring name);
	~Planet();

	void Update();
	void Render();

	
	void SetRotation(float speed) { _rotationSpeed = speed; }
	void SetScale(Vector2 scale);
	void SetPosition(Vector2 pos);
	void SetParent(shared_ptr<Transform> trans);

	// Transform을 직접 꺼내는 것보단 위에처럼 세팅해주는 함수를 따로 만들어 주는것이 디버깅하기가 쉬움
	shared_ptr<Transform> GetTransform() { return _trans; }
	shared_ptr<Transform> GetOrbit() { return _orbit; }
	
private:

	float _rotationSpeed = 0.0001f;
	shared_ptr<Transform> _orbit;
	shared_ptr<Transform> _trans;
	shared_ptr<Quad> _quad;
	



};

