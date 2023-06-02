#pragma once
class Transform
{
public:
	Transform();
	~Transform();

	void Update();
	void Update_WorldBuffer();
	void Update_SRT();

	void SetPosition(Vector2 pos) { _pos = pos; }
	void SetScale(Vector2 sclae) { _scale = sclae; }
	void SetAngle(float angle) { _angle = angle; }
	void SetWorldBuffer(UINT slot);

	void AddVector2(Vector2 pos) { _pos += pos; }
	void AddSclae(Vector2 scale) { _scale += scale; }
	void AddAngle(float angle) { _angle += angle; }
	

private:


	Vector2 _pos;
	Vector2 _scale = {1.0f,1.0f};

	float _angle = 0.0f;


	XMMATRIX _srtMatrix = XMMatrixIdentity();

	shared_ptr<class MatrixBuffer> _world;

};

