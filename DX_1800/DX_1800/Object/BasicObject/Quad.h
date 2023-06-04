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


	// ������Ʈ ����
	// ��ǰó�� �����ִ� ���
	// ex) ���尡 Ʈ�������� ��������Ƿ� ������ ��������
	// mash == �������� ���� -> vretices, indices, vertexbuffer, indexbuffr
	// material ==  ������Ʈ ǥ���� ���� ��� -> vs, ps, srv, sampler 
	shared_ptr<Transform> _transform;


};

