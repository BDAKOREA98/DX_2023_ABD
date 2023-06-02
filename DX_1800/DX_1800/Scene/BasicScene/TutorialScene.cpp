#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
    _qurd = make_shared<Qurd>(L"Resource/Texture/chaewon.png");

    
    _view = make_shared<MatrixBuffer>();
    _proj = make_shared<MatrixBuffer>();

    _transform = make_shared<Transform>();
   
    _view->Update_Resource();

    // 화면에 비율을 미리 곱해줌

    XMMATRIX temp = XMMatrixOrthographicOffCenterLH
    (0,WIN_WIDTH,0, WIN_HEIGHT, 0.0f, 1.0f);


    _proj->SetData(temp);
    _proj->Update_Resource();
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
  //사진 이동하기
    if (GetAsyncKeyState('D'))
    {
        _transform->AddVector2(Vector2(0.1f, 0.0f));
        _transform->Update();
    }
    if (GetAsyncKeyState('A'))
    {
        _transform->AddVector2(Vector2(-0.1f, 0.0f));
        _transform->Update();
    }
    if (GetAsyncKeyState('W'))
    {
        _transform->AddVector2(Vector2(0.0f, 0.1f));
        _transform->Update();
    }
    if (GetAsyncKeyState('S'))
    {
        _transform->AddVector2(Vector2(0.0f, -0.1f));
        _transform->Update();
    }
  
    if (GetAsyncKeyState('O'))
    {
        _transform->AddSclae(Vector2(0.005f, 0.005f));
        _transform->Update();
    }
    if (GetAsyncKeyState('P'))
    {
        _transform->AddSclae(Vector2(-0.005f, -0.005f));
        _transform->Update();
    }
    if (GetAsyncKeyState('Q'))
    {
        _transform->AddAngle(0.005f);
        _transform->Update();
    }
    if (GetAsyncKeyState('E'))
    {
        _transform->AddAngle(-0.005f);
        _transform->Update();
    }
    
   
 
   _transform->Update();
 
    _qurd->Update();


}

void TutorialScene::Render()
{

    _transform->SetWorldBuffer(0);

    _view->SetVS_Buffer(1);
    _proj->SetVS_Buffer(2);
   
    _qurd->Render();


}
