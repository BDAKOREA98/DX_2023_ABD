#pragma once
#include "../../Types.h"

class RectCollider
{
public:
	RectCollider(Vector2 size);
	~RectCollider();

	void Update();
	void Render();

	void CreateVertices();
	void CreateData();

	void SetRed() { _colorBuffer->SetColor(RED); }
	void SetGreen() { _colorBuffer->SetColor(GREEN); }
	void SetBlue() { _colorBuffer->SetColor(BLUE); }
	void SetWhite() { _colorBuffer->SetColor(WHITE); }





	shared_ptr<Transform> GetTranform() { return _transform; }

private:
	Vector2 _size;

	shared_ptr<ColorBuffer> _colorBuffer;


	shared_ptr<Transform> _transform;

	vector<Vertex> _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;

	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;



};

