#pragma once
class DunBow
{
public:

	DunBow(wstring path);
	~DunBow();

	void Update();
	void Render();


	void CreateVertices();
	void CreateData(wstring path);

	shared_ptr<Transform> GetTransform() { return _transform; }

private:


	vector<Vertex_Texture> _vertices;
	vector<UINT> _indices;



	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<SRV> _srv;
	shared_ptr<Transform> _transform;


};

