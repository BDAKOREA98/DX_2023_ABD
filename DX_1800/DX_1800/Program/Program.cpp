#include "framework.h"
#include "Program.h"

#include "../Scene/BasicScene/TutorialScene.h"
#include "../Scene/BasicScene/SolarSystem.h"
#include "../Scene/BasicScene/DunGreed.h"
#include "../Scene/BasicScene/ColliderScene.h"
#include "../Scene/BasicScene/SpriteScene.h"
#include "../Scene/BasicScene/ZeldaScene.h"
#include "../Scene/BasicScene/CupHeadScene.h"

Program::Program()
{
    srand(static_cast<unsigned int> (time(nullptr)));
	_curscene = make_shared<TutorialScene>();

    _view = make_shared<MatrixBuffer>();
    _proj = make_shared<MatrixBuffer>();


    _view->Update_Resource();

    // ȭ�鿡 ������ �̸� ������

    XMMATRIX temp = XMMatrixOrthographicOffCenterLH
    (0, WIN_WIDTH, 0, WIN_HEIGHT, 0.0f, 1.0f);


    _proj->SetData(temp);
    _proj->Update_Resource();
    Timer::GetInstance()->LockFPS(60);
}

Program::~Program()
{
}

void Program::Update()
{
    Timer::GetInstance()->Update();
    InputManager::GetInstance()->Update();

    _curscene->Update();
    EFFECT->Update();
    SOUND->Update();

}

void Program::Render()
{
	Device::GetInstance()->Clear();


    _view->SetVS_Buffer(1);
    _proj->SetVS_Buffer(2);


    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();


    ALPHA->SetState();
	_curscene->Render();
    EFFECT->Render();
    


    ImGui::Text("FPS : %d", FPS);
    ImGui::Text("DeltaTime : %1f", DELTA_TIME);
    ImGui::Text("RunTime : %1f", RUN_TIME);
    _curscene->PostRender();
    


    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();

}
