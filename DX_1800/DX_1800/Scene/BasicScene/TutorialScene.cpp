#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
    _qurd = make_shared<Qurd>(L"Resource/Texture/chaewon.png");

    _qurd->GetTransform()->SetPosition(CENTER);
    _qurd->GetTransform()->SetScale(Vector2(0.7f,0.7f));
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
  //사진 이동하기
    if (GetAsyncKeyState('D'))
    {
        _qurd->GetTransform()->AddVector2(Vector2(0.1f, 0.0f));
        _qurd->GetTransform()->Update();
    }
    if (GetAsyncKeyState('A'))
    {
        _qurd->GetTransform()->AddVector2(Vector2(-0.1f, 0.0f));
        _qurd->GetTransform()->Update();
    }
    if (GetAsyncKeyState('W'))
    {
        _qurd->GetTransform()->AddVector2(Vector2(0.0f, 0.1f));
        _qurd->GetTransform()->Update();
    }
    if (GetAsyncKeyState('S'))
    {
        _qurd->GetTransform()->AddVector2(Vector2(0.0f, -0.1f));
        _qurd->GetTransform()->Update();
    }
  
    if (GetAsyncKeyState('O'))
    {
        _qurd->GetTransform()->AddSclae(Vector2(0.005f, 0.005f));
        _qurd->GetTransform()->Update();
    }
    if (GetAsyncKeyState('P'))
    {
        _qurd->GetTransform()->AddSclae(Vector2(-0.005f, -0.005f));
        _qurd->GetTransform()->Update();
    }
    if (GetAsyncKeyState('Q'))
    {
        _qurd->GetTransform()->AddAngle(0.005f);
        _qurd->GetTransform()->Update();
    }
    if (GetAsyncKeyState('E'))
    {
        _qurd->GetTransform()->AddAngle(-0.005f);
        _qurd->GetTransform()->Update();
    }
    
   
 

 
    _qurd->Update();


}

void TutorialScene::Render()
{

  

    _qurd->Render();


}
