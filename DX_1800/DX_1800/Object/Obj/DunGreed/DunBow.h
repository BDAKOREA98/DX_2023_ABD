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

	

private:


	vector<Vertex_Texture> _vertices;
	vector<UINT> _indices;



	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<SRV> _srv;

};

