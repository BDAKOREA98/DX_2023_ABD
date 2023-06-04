#pragma once
class Quad
{
public:

	Quad(wstring path);
	~Quad();

	void Update();
	void Render();


	void CreateVertices();
	void CreateData(wstring path);

	shared_ptr<Transform> GetTransform() { return _transform; }

private:


	vector<Vertex> _vertices;
	vector<UINT> _indices;



	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<SRV> _srv;
	shared_ptr<SamplerState> _sampler;


	// 컴포넌트 패턴
	// 부품처럼 끼워넣는 방식
	// ex) 쿼드가 트랜스폼을 들고있으므로 변형이 가능해짐
	// mash == 정점들의 모임 -> vretices, indices, vertexbuffer, indexbuffr
	// material ==  오브젝트 표면의 질감 등등 -> vs, ps, srv, sampler 
	shared_ptr<Transform> _transform;


};

