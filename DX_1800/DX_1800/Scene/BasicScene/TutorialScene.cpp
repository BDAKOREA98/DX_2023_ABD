#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
    _qurd = make_shared<Qurd>(L"Resource/Texture/chaewon.png");

}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
    _qurd->Update();
}

void TutorialScene::Render()
{
    _qurd->Render();


}
