#include "framework.h"
#include "DunBow.h"

DunBow::DunBow(wstring path)
{
	_srv = make_shared<SRV>(path);

	CreateVertices();
	CreateData(path);
}

DunBow::~DunBow()
{
}

void DunBow::Update()
{
	
}

void DunBow::Render()
{

    _vertexBuffer->SetIA_VertexBuffer();
    _indexBuffer->SetIA_IndexBuffer();


    _vs->SetIAInputLayout();

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    _srv->SetSRV(0);
    SAMPLER->SetSampler();

    _vs->Set();
    _ps->Set();

    DC->DrawIndexed(_indices.size(), 0, 0);
}

void DunBow::CreateVertices()
{
    Vertex_Texture v;

    Vector2 halfSize = _srv->GetImageze() * 0.5;

    v.pos = { -halfSize.x , halfSize.y, 0.0f }; // 왼쪽 위 
    v.color = { 1.0f, 0.0f, 0.0f, 1.0f };
    v.uv = { 0.0f, 0.0f };
    _vertices.push_back(v);

    v.pos = { halfSize.x , halfSize.y, 0.0f }; // 오른쪽 위
    v.color = { 0.0f, 1.0f, 0.0f, 1.0f };
    v.uv = { 1.0f, 0.0f };
    _vertices.push_back(v);


    v.pos = { halfSize.x, -halfSize.y, 0.0f }; // 오른쪽 아래
    v.color = { 0.0f, 0.0f, 1.0f, 1.0f };
    v.uv = { 1.0f, 1.0f };
    _vertices.push_back(v);

    v.pos = { -halfSize.x, -halfSize.y, 0.0f }; // 왼쪽 아래
    v.color = { 1.0f, 1.0f, 1.0f, 1.0f };
    v.uv = { 0.0f, 1.0f };
    _vertices.push_back(v);


    _indices.push_back(0);
    _indices.push_back(1);
    _indices.push_back(2);

    _indices.push_back(0);
    _indices.push_back(2);
    _indices.push_back(3);
}

void DunBow::CreateData(wstring path)
{
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_Texture), _vertices.size());
    _indexBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());

    _vs = make_shared<VertexShader>(L"Shader/TextureVS.hlsl");

    _ps = make_shared<PixelShader>(L"Shader/DunBow.hlsl");

}
