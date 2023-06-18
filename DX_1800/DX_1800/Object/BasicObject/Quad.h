#pragma once
class Quad
{
protected:
	Quad() {}
public:

	Quad(wstring path);
	Quad(wstring path, Vector2 size);
	virtual ~Quad();

	virtual void Update();
	virtual void Render();


	virtual void CreateVertices();
	virtual void CreateData(wstring path);

	shared_ptr<PixelShader> ChangePS(wstring file) { _ps = make_shared<PixelShader>(file); }

	

protected:


	vector<Vertex_Texture> _vertices;
	vector<UINT> _indices;



	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	
	weak_ptr<VertexShader> _vs;
	weak_ptr<PixelShader> _ps;
	
	weak_ptr<SRV> _srv;


	// ������Ʈ ����
	// ��ǰó�� �����ִ� ���
	// ex) ���尡 Ʈ�������� ��������Ƿ� ������ ��������
	// mash == �������� ���� -> vretices, indices, vertexbuffer, indexbuffr
	// material ==  ������Ʈ ǥ���� ���� ��� -> vs, ps, srv, sampler 
	

	Vector2 _size;

};

