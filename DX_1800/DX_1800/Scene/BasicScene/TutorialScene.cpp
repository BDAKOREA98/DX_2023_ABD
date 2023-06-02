#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
    _qurd = make_shared<Qurd>(L"Resource/Texture/chaewon.png");

    _world = make_shared<MatrixBuffer>();
    _view = make_shared<MatrixBuffer>();
    _proj = make_shared<MatrixBuffer>();

    _world->Update_Resource();
    _view->Update_Resource();

    // 화면에 비율을 미리 곱해줌

    XMMATRIX temp = XMMatrixOrthographicOffCenterLH(0,WIN_WIDTH,0, WIN_HEIGHT, 0.0f, 1.0f);


    _proj->SetData(temp);
    _proj->Update_Resource();
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
    //사진 이동하기
    _x += 0.1;
    XMMATRIX translate = XMMatrixTranslation(_x, _y, 0);

    _world->SetData(translate);
    _world->Update_Resource();

    _qurd->Update();
}

void TutorialScene::Render()
{

    _world->SetVS_Buffer(0);
    _view->SetVS_Buffer(1);
    _proj->SetVS_Buffer(2);

    _qurd->Render();


}
