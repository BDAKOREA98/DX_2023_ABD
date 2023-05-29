// DX_1800.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "DX_1800.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// DX : Direct Accesss...
// 1980 x 1080 등의 작은 계산들을 GPU한테 맡기는 외주 맡기는 스토리

// CPU vs GPU
// CPU
// - 소수의 교수님
// - 어려운 계산 작업을 직렬 처리한다.
// GPU
// - 수많은 다수의 초등생 
// - 단순한 계산을 병력처리하는데 특화되어있다.
//
//

// DX 그래픽스
// - 영화촬영 과 게임제작은 비슷하다.
// - 카메라   /  카메라
// - 세트장   /  Would
// - 총감독   /  프로그래머
// - 조명     /  Light
// - 영화사   /  엔진(u ity, unreal... etc)
//  
//

// device : 주로 그래픽 렌더링을 위한 디바이스 장치를 가리킨다. (GPU) 
// device context : 그래픽스 및 렌더링 명령을 실행하기 위한 인터페이스 (인터페이스 = 차로치면 문 손잡이같은것 )
// swap chain : 그래픽 출력을 관리하는 데 사용되는 개체 - 그래픽 버퍼를 관리함, 더블버퍼링 및 수직동기화 같은 기능을 제공함
// - 수직동기화를 끄면 아직 화면은 안 돌아도 일단 돌아있는 상태로 만듬
// RenderTargetView : 그래픽 출력이 렌더링 되는 대상을 나타내는 개체
// Viewport : 그래픽 출력의 영역을 정의하는 개체 (unity라면 카메라의 피라미드같은것 )
// 렌더링 파이프 라인 : 그래픽스 객체의 렌더링 작업을 처리하는 일련의 단계 - 3D의 객체나 모델이 2D 과정으로 그리기위해 거치는 단계
// vertexBuffer : 그래픽스 객체의 정점 데이터를 저장하는 버퍼
// InputLayout : 그래픽스 객체의 정점 데이터 형식을 정의 하는 개체
// vertexshader : 그래픽스 파이프 라인의 정점 셰이더 단계를 구현하는 개체
// pixelshader : 그래픽스 파이프 라인의 픽셀 셰이더 단계를 구현하는 개체
//

// DX 2D
// 컴퓨터 그래픽스
// 랜더링 파이프라인 : GPU를 사용해 리소스를 2D 이미지로 렌더링 하는 과정
// - 리소스 : 3D공간의 가상의 정점
// -> 3D 공간의 어떤 좌표를 모니터에 표시하기까지 걸리는 일련의 과정
// 1. 
//




// 인력사무소장
// - 외주를 맡기고 실질적인 노가다 대표 뽑기
// - 컴퓨터의 하드웨어 기능 점검, 리소스 할당 하는 애들을 뽑아주는 애 

Microsoft::WRL::ComPtr<ID3D11Device> device; // 외주맡기는데 필요한 애들을 이것을 이용해서 고용할 예정
// Dirext X 를 사용할때는 sheardptr이 아닌 comptr을 사용한다. microsoft에서 만든 객체지향성 포인트
// why?? => device = new ID3D11Device(); 이런 형식으로 만드는것이 아님 --- new를 이용해서 동적할당 하는것이 아니다.
// API처럼 Create 로 생성 지울땐 release로 관리하기에 sheard로 관리가 안됨 ' 즉 delete하면 터진다.
// microsoft에서 만든 스마트 포인터 == ComPtr

// 연출감독
// 세트장을 실질적으로 꾸며주는 연출가
// 렌더링 대상 결정(어디에 그릴지 결정해줌)
// -> 리소스를 그래픽 파이프라인에 바인딩함, 리소스 할당
ComPtr<ID3D11DeviceContext> deviceContext; // DC라고 부름

// DX의 인터페이스로써 1개이상의 표면을 포함할 수 있다.
// 각각의 표면 (버퍼, 텍스쳐) 를 출력하기 전에 데이터를 보관한다.
ComPtr<IDXGISwapChain> swapChain;

// 버퍼와 텍스쳐의 역할은 거의 동일하다고 보면 된다. 
// 버퍼 : 누구한테 받거나 전달하기위한 임시 저장소까지 들고있음
// 텍스쳐 : 갖고있는 정보를 그대로 표출
// 후면 버퍼를 가리키는 포인터
// 후면 버퍼 == 지금 당장 그릴 곳
ComPtr<ID3D11RenderTargetView> renderTargetView;

// 렌더링 파이프 라인 단계
ComPtr<ID3D11Buffer> vertexBuffer;
// 3D구간의 정점(CPU에 있는 정점)을 GPU한테 전달
ComPtr<ID3D11InputLayout> inputLayout;
// layeout == 배치, 입력
// CPU와 GPU가 서로 아는가?? -> NO 서로 별개의 존재같은 느낌(외계인보듯)
// 전달하는 내용은 010101의 2진법 전기신호일 것
// vertex컬러 정보를 전달하고 싶다면? ...-> GPU가 잘 못 읽을 수 있음
// 제대로 정보전달을 읽게하기 위해 정보를 읽는 방법을 동봉해야함 == inputLayout
ComPtr<ID3D11VertexShader> vertexShader;
ComPtr<ID3D11PixelShader> pixelShader;

HWND hWnd;

struct Vertex
{
    XMFLOAT3 pos;

};

void InitDevice();
void Render();




// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DX1800, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DX1800));

    // 생성
    InitDevice();


    MSG msg = {};

    // 기본 메시지 루프입니다:
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
             if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
             {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
              }
        }
        else
        {
            // 메인 루프
            Render();
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DX1800));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DX1800);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void InitDevice()
{
    RECT rc;
    GetClientRect(hWnd, &rc);
    UINT width = rc.right - rc.left;
    UINT height = rc.bottom - rc.top;

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

    ComPtr<ID3D11Texture2D> backBuffer;

    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)backBuffer.GetAddressOf());
    device->CreateRenderTargetView(backBuffer.Get(), nullptr, renderTargetView.GetAddressOf());

    deviceContext->OMSetRenderTargets(1, renderTargetView.GetAddressOf(), nullptr); // OM (out put merge) // 병합단계

    D3D11_VIEWPORT vp; // 카메라의 큰 사각형의 설명서
    vp.Width = width;
    vp.Height = height;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    deviceContext->RSSetViewports(1, &vp); // 레스터화 단계

    D3D11_INPUT_ELEMENT_DESC layOut[] =
    {
        {
            "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,0,0,
            //                RGB가 32bit => 12byte    start
            D3D11_INPUT_PER_VERTEX_DATA,0
            // vertex마다의 데이터

        }
    };

    UINT layOutSize = ARRAYSIZE(layOut);
    
    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

   
    
    //wstring temp;
    // 

    // vertexShader 만들기
    ComPtr<ID3DBlob> vertexBlob; // vertexShader 만들때 필요한 애

    D3DCompileFromFile(L"Shader/Tutorial_Shader.hlsl", nullptr, nullptr, 
        "VS", "vs_5_0", flags, 0, vertexBlob.GetAddressOf(), nullptr);

    device->CreateInputLayout(layOut, layOutSize, vertexBlob->GetBufferPointer(),
        vertexBlob->GetBufferSize(), IN inputLayout.GetAddressOf());

    device->CreateVertexShader(vertexBlob->GetBufferPointer(), vertexBlob->GetBufferSize(),
        nullptr, IN vertexShader.GetAddressOf());

    // pixelShader 만들기
    ComPtr<ID3DBlob> pixelBlob;

    D3DCompileFromFile(L"Shader/Tutorial_Shader.hlsl", nullptr, nullptr,
        "PS", "ps_5_0", flags, 0, pixelBlob.GetAddressOf(), nullptr);

    device->CreatePixelShader(pixelBlob->GetBufferPointer(),
        pixelBlob->GetBufferSize(), nullptr, IN pixelShader.GetAddressOf());

    // 3차원 공간을 표현할 수 있는 사용자 정의 자료형
    vector<Vertex> vertices;

    // 정점들 배열 생성
    Vertex v;
    v.pos = { 0.0f , 0.5f, 0.0f }; // 위 
    vertices.push_back(v);
    v.pos = { 0.5f , -0.5f, 0.0f }; // 오른쪽 아래
    vertices.push_back(v);
    v.pos = { -0.5f, -0.5f, 0.0f }; // 왼쪽 아래
    vertices.push_back(v);

    // 정점버퍼들한테 담아서 보내주기
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(Vertex) * vertices.size(); // 12 * 3 = 36byye 전체 크기
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = vertices.data();  // vector의 첫 번째 주소를 반환 => vertices.data() == &vertices[0]
    // RAM 정보들을 GPU로 보낼때 시작지점과 끝나는 지점을 알아야함!
    // 1개씩 나눠서 vertex가 몇개인지, 1개당 몇바이트인지, 몇개있는지, 어디서부터 유효한정보가 시작인지 알려줘야함!

    device->CreateBuffer(&bd, &initData, IN vertexBuffer.GetAddressOf());


}

void Render()
{
    FLOAT myColorR = 0.0f;
    FLOAT myColorG = 0.0f;
    FLOAT myColorB = 0.0f;

    FLOAT clearColor[4] = { myColorR, myColorG, myColorB, 1.0f };

    deviceContext->ClearRenderTargetView(renderTargetView.Get(), clearColor); // 배경 만들기

    deviceContext->IASetInputLayout(inputLayout.Get());
    UINT stride = sizeof(Vertex);
    UINT offset = 0;
    deviceContext->IASetVertexBuffers(0, 1, vertexBuffer.GetAddressOf(), &stride, &offset);

    deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);// 삼각형 형식으로 그리는 방법

    deviceContext->VSSetShader(vertexShader.Get(), nullptr, 0);
    deviceContext->PSSetShader(pixelShader.Get(), nullptr, 0);

    deviceContext->Draw(3,0); // vertex개수 3, 시작할 번호 0번째

    swapChain->Present(0, 0);

}
