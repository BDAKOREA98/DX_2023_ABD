#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
    _qurd = make_shared<Quad>(L"Resource/Texture/chaewon.png");
     _qurd->SetPS(ADD_PS(L"Shader/FillterPS.hlsl"));
   
    _trans = make_shared<Transform>();
   _trans->SetPosition(CENTER);



    _trans->SetScale(Vector2(0.7f,0.7f));
   _filterBuffer = make_shared<FilterBuffer>();
   _filterBuffer->_data.imageSize = _qurd->GetImageSize();
   _filterBuffer->_data.radiaCenter = {0.5f, 0.5f};


  // _effect = make_shared<Effect>("Hit", L"Resource/Texture/hit_4x2.png", Vector2(4, 2), Vector2(100, 100));
  
   //EFFECT->AddEffect("Hit", L"Resource/Texture/hit_4x2.png", Vector2(4, 2), Vector2(100, 100));
   EFFECT->AddEffect_("Hit", L"Resource/CupHead/Effect/Hyper_Shot_End.png", L"Resource/CupHead/Effect/Hyper_Shot_End.xml",
       Vector2(500,500));
   SOUND->Add("bgm1", "Resource/Sound/BGM.mp3", true);
   SOUND->Add("attack", "Resource/Sound/attack.wav", true);


   SOUND->Pause("bgm1");

}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
  //사진 이동하기
    if (GetAsyncKeyState('D'))
    {
        _trans->AddVector2(RIGHT_VECTOR);
        _trans->Update();
    }
    if (GetAsyncKeyState('A'))
    {
        _trans->AddVector2(LEFT_VECTOR);
        _trans->Update();
    }
    if (GetAsyncKeyState('W'))
    {
        _trans->AddVector2(UP_VECTOR);
        _trans->Update();
    }
    if (GetAsyncKeyState('S'))
    {
        _trans->AddVector2(DOWN_VECTOR);
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
    
   
 

    _filterBuffer->Update_Resource();
    _trans->Update();
    _qurd->Update();

    if (KEY_DOWN(VK_LBUTTON))
    {
       // _effect->Play(MOUSE_POS);
       
        EFFECT->Play("Hit", CENTER);
        //SOUND->Play("attack");

    }

       // _effect->Update();
      
}

void TutorialScene::Render()
{

  

    _trans->SetWorldBuffer(0);
    _filterBuffer->SetPS_Buffer(0);
    _qurd->Render();

   // _effect->Render();
   
   
}

void TutorialScene::PostRender()
{
    ImGui::SliderInt("selected", &_filterBuffer->_data.seleted, 0, 6);
    ImGui::SliderInt("value1", &_filterBuffer->_data.value1, 0, 300);
    ImGui::SliderInt("value2", &_filterBuffer->_data.value2, 0, 300);
    ImGui::SliderInt("value3", &_filterBuffer->_data.value3, 0, 300);
}
