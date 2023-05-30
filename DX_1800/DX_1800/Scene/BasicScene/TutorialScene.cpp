#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
    CreateVertices();
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
    _vs = make_shared<VertexShader>(L"Shader/TextureVS.hlsl");
    _ps = make_shared<PixelShader>(L"Shader/TexturePS.hlsl");

    _srv = make_shared<SRV>(L"Resource/Texture/chaewon.png");
    _sampler = make_shared<SamplerState>();

}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
}

void TutorialScene::Render()
{
    _vertexBuffer->SetIA_VertexBuffer();
    _vs->SetIAInputLayout();

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    _srv->SetSRV(0);

    _sampler->SetSampler();

    _vs->Set_VS();
    _ps->Set_PS();

    DC->Draw(_vertices.size(), 0);



}

void TutorialScene::CreateVertices()
{
    Vertex v;
    v.pos = { -0.5f , 0.5f, 0.0f }; // 왼쪽 위 
    v.color = { 1.0f, 0.0f, 0.0f, 1.0f };
    v.uv = { 1.0f, 0.0f };
    _vertices.push_back(v);

    v.pos = { 0.5f , 0.5f, 0.0f }; // 오른쪽 위
    v.color = { 0.0f, 1.0f, 0.0f, 1.0f };
    v.uv = { 0.0f, 0.0f };
    _vertices.push_back(v);

    v.pos = { 0.5f, -0.5f, 0.0f }; // 오른쪽 아래
    v.color = { 0.0f, 0.0f, 1.0f, 1.0f };
    v.uv = { 0.0f, 1.0f };
    _vertices.push_back(v);

    //  사각형 아랫부분 
    v.pos = { -0.5f, 0.5f, 0.0f }; // 왼쪽 위 
    v.color = { 1.0f, 0.0f, 0.0f, 1.0f };
    v.uv = { 1.0f, 0.0f };
    _vertices.push_back(v);

    v.pos = { 0.5f, -0.5f, 0.0f }; // 오른쪽 아래
    v.color = { 0.0f, 0.0f, 1.0f, 1.0f };
    v.uv = { 0.0f, 1.0f };
    _vertices.push_back(v);

    v.pos = { -0.5f, -0.5f, 0.0f }; // 왼쪽 아래
    v.color = { 1.0f, 1.0f, 1.0f, 1.0f };
    v.uv = { 1.0f, 1.0f };
    _vertices.push_back(v);


    
}
