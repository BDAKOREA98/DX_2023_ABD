#pragma once
class Quad
{
public:

	Quad(wstring path);
	Quad(wstring path, Vector2 size);
	~Quad();

	void Update();
	void Render();


	void CreateVertices();
	void CreateData(wstring path);
	shared_ptr<PixelShader> ChangePS(wstring file) { _ps = make_shared<PixelShader>(file); }

	

private:


	vector<Vertex_Texture> _vertices;
	vector<UINT> _indices;



	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<SRV> _srv;


	// 컴포넌트 패턴
	// 부품처럼 끼워넣는 방식
	// ex) 쿼드가 트랜스폼을 들고있으므로 변형이 가능해짐
	// mash == 정점들의 모임 -> vretices, indices, vertexbuffer, indexbuffr
	// material ==  오브젝트 표면의 질감 등등 -> vs, ps, srv, sampler 
	

	Vector2 _size;

};

