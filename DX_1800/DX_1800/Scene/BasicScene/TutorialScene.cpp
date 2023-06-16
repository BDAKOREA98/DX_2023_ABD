#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
    _qurd = make_shared<Quad>(L"Resource/Texture/chaewon.png");
   
    _trans = make_shared<Transform>();
   _trans->SetPosition(CENTER);
    _trans->SetScale(Vector2(0.7f,0.7f));
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
  //사진 이동하기
    if (GetAsyncKeyState('D'))
    {
        _trans->AddVector2(Vector2(0.1f, 0.0f));
        _trans->Update();
    }
    if (GetAsyncKeyState('A'))
    {
        _trans->AddVector2(Vector2(-0.1f, 0.0f));
        _trans->Update();
    }
    if (GetAsyncKeyState('W'))
    {
        _trans->AddVector2(Vector2(0.0f, 0.1f));
        _trans->Update();
    }
    if (GetAsyncKeyState('S'))
    {
        _trans->AddVector2(Vector2(0.0f, -0.1f));
        _trans->Update();
    }
  
    if (GetAsyncKeyState('O'))
    {
        _trans->AddSclae(Vector2(0.005f, 0.005f));
        _trans->Update();
    }
    if (GetAsyncKeyState('P'))
    {
        _trans->AddSclae(Vector2(-0.005f, -0.005f));
        _trans->Update();
    }
    if (GetAsyncKeyState('Q'))
    {
        _trans->AddAngle(0.005f);
        _trans->Update();
    }
    if (GetAsyncKeyState('E'))
    {
        _trans->AddAngle(-0.005f);
        _trans->Update();
    }
    
   
 

 
    _qurd->Update();
    _trans->Update();

}

void TutorialScene::Render()
{

  

    _qurd->Render();
    _trans->SetWorldBuffer(0);

}
