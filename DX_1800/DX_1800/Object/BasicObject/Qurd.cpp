#include "framework.h"
#include "Qurd.h"



Qurd::Qurd(wstring path)
{
    _srv = make_shared<SRV>(path);
    _sampler = make_shared<SamplerState>();

	CreateVertices();
	CreateData(path);

    _transform = make_shared<Transform>();

	
}

Qurd::~Qurd()
{
}

void Qurd::Update()
{
    _transform->Update();
}

void Qurd::Render()
{
    _transform->SetWorldBuffer(0);
    
    _vertexBuffer->SetIA_VertexBuffer();
    _indexBuffer->SetIA_IndexBuffer();


    _vs->SetIAInputLayout();

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    _srv->SetSRV(0);

    _sampler->SetSampler();

    _vs->Set_VS();
    _ps->Set_PS();

    DC->DrawIndexed(_indices.size(), 0, 0);

}

void Qurd::CreateVertices()
{

    Vertex v;

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

void Qurd::CreateData(wstring path)
{



	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
    _indexBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());
    
    _vs = make_shared<VertexShader>(L"Shader/TextureVS.hlsl");
	_ps = make_shared<PixelShader>(L"Shader/TexturePS.hlsl");

   

}
