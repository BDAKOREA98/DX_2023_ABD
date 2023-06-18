#include "framework.h"
#include "VertexShader.h"

VertexShader::VertexShader(wstring path)
{
	CreateBlob(path);
	CreateInputLayout();
	CreateVertexShader();
}

VertexShader::~VertexShader()
{
}

void VertexShader::CreateBlob(wstring path)
{

	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

	

	D3DCompileFromFile(path.c_str(), nullptr, nullptr,
		"VS", "vs_5_0", flags, 0, _blob.GetAddressOf(), nullptr);


}

void VertexShader::CreateInputLayout()
{

    D3D11_INPUT_ELEMENT_DESC layOut[] =
    {
        {
            "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,0,0,
            //                RGB가 32bit => 12byte    start
            D3D11_INPUT_PER_VERTEX_DATA,0
            // vertex마다의 데이터

        },
        {
            "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,
            D3D11_INPUT_PER_VERTEX_DATA, 0
        },
        {
            "UV" , 0, DXGI_FORMAT_R32G32_FLOAT, 0, 28,
            D3D11_INPUT_PER_VERTEX_DATA, 0
        }
    };

    UINT layOutSize = ARRAYSIZE(layOut);



    DEVICE->CreateInputLayout(layOut, layOutSize, _blob->GetBufferPointer(),
        _blob->GetBufferSize(), IN _inputLayout.GetAddressOf());


}

void VertexShader::CreateVertexShader()
{

    DEVICE->CreateVertexShader(_blob->GetBufferPointer(), _blob->GetBufferSize(),
        nullptr, IN _vs.GetAddressOf());
}

void VertexShader::SetIAInputLayout()
{

    DC->IASetInputLayout(_inputLayout.Get());
}

void VertexShader::Set()
{
    DC->VSSetShader(_vs.Get(), nullptr, 0);
}


