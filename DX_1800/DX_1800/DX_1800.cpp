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



// 3D구간의 정점(CPU에 있는 정점)을 GPU한테 전달
// layeout == 배치, 입력
// CPU와 GPU가 서로 아는가?? -> NO 서로 별개의 존재같은 느낌(외계인보듯)
// 전달하는 내용은 010101의 2진법 전기신호일 것
// vertex컬러 정보를 전달하고 싶다면? ...-> GPU가 잘 못 읽을 수 있음
// 제대로 정보전달을 읽게하기 위해 정보를 읽는 방법을 동봉해야함 == inputLayout




HWND hWnd;





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
    Device::Create();

    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplWin32_Init(hWnd);
    ImGui_ImplDX11_Init(DEVICE.Get(), DC.Get());

    Timer::Create();
    InputManager::Create();
    SRVManager::Create();
    StateManager::Create();
    ShaderManager::Create();
    EffectManager::Create();
    SoundManager::Create();

    shared_ptr<Program> program = make_shared<Program>();

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
            program->Update();
            program->Render();


        }
    }

    // 삭제
    SoundManager::Delete();
    EffectManager::Delete();
    ShaderManager::Delete();
    StateManager::Delete();
    SRVManager::Delete();
    InputManager::Delete();
    Timer::Delete();

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();


    Device::Delete();

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
      0, 0, // 윈도우창 시작지점
       WIN_WIDTH, WIN_HEIGHT, // 크기
       nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   // 메뉴 숨기기
   SetMenu(hWnd, nullptr);
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

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam))
    {
        return true;
    }

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

        // 마우스커서 따라오기
    case WM_MOUSEMOVE:
    {
        Vector2 mousePos;
        mousePos.x = static_cast<float>(LOWORD(lParam));
        mousePos.y = WIN_HEIGHT - static_cast<float>(HIWORD(lParam));

        InputManager::GetInstance()->SetMousePos(mousePos);
        break;
    }

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

