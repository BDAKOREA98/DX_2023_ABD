#include "framework.h"
#include "Device.h"

Device* Device::_instance = nullptr;
// 스태틱 변수는 무조건 전역에서 초기화

Device::Device()
{
	CreateDeviceAndSwapChain();
	CreateDoubleBuffer();
}

Device::~Device()
{

}

void Device::Clear()
{
    FLOAT myColorR = 0.0f;
    FLOAT myColorG = 0.0f;
    FLOAT myColorB = 0.0f;

    FLOAT clearColor[4] = { myColorR, myColorG, myColorB, 1.0f };

    deviceContext->ClearRenderTargetView(renderTargetView.Get(), clearColor); // 배경 만들기

}

void Device::Present()
{
    swapChain->Present(0, 0);
}

void Device::CreateDeviceAndSwapChain()
{
    RECT rc;
    GetClientRect(hWnd, &rc);
    UINT width = WIN_WIDTH;
    UINT height = WIN_HEIGHT;

    D3D_FEATURE_LEVEL featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0

    };

    UINT featureSize = ARRAYSIZE(featureLevels);

    DXGI_SWAP_CHAIN_DESC sd = {};
    sd.BufferCount = 1;
    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    // numerator 나누기 Denominator = > 화면 프레인 갱신 속도
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = true; // 창모드

    D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        0,
        D3D11_CREATE_DEVICE_DEBUG,
        featureLevels,
        featureSize,
        D3D11_SDK_VERSION, // 개발 툴??
        &sd,
        IN swapChain.GetAddressOf(),// 포인터 자체의 원본을 가져온다 - 더블 포인터
        IN device.GetAddressOf(),
        nullptr,
        IN deviceContext.GetAddressOf()
    );

}

void Device::CreateDoubleBuffer()
{

    ComPtr<ID3D11Texture2D> backBuffer;

    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)backBuffer.GetAddressOf());
    device->CreateRenderTargetView(backBuffer.Get(), nullptr, renderTargetView.GetAddressOf());

    deviceContext->OMSetRenderTargets(1, renderTargetView.GetAddressOf(), nullptr); // OM (out put merge) // 병합단계

    D3D11_VIEWPORT vp; // 카메라의 큰 사각형의 설명서
    vp.Width = WIN_WIDTH;
    vp.Height = WIN_HEIGHT;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    deviceContext->RSSetViewports(1, &vp); // 레스터화 단계

}
