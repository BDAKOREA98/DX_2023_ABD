#include "framework.h"
#include "Program.h"

#include "../Scene/BasicScene/TutorialScene.h"
#include "../Scene/BasicScene/SolarSystem.h"
#include "../Scene/BasicScene/DunGreed.h"
#include "../Scene/BasicScene/ColliderScene.h"

Program::Program()
{
	_curscene = make_shared<ColliderScene>();

    _view = make_shared<MatrixBuffer>();
    _proj = make_shared<MatrixBuffer>();


    _view->Update_Resource();

    // ȭ�鿡 ������ �̸� ������

    XMMATRIX temp = XMMatrixOrthographicOffCenterLH
    (0, WIN_WIDTH, 0, WIN_HEIGHT, 0.0f, 1.0f);


    _proj->SetData(temp);
    _proj->Update_Resource();
}

Program::~Program()
{
}

void Program::Update()
{
    Timer::GetInstance()->Update();
    InputManager::GetInstance()->Update();

    _curscene->Update();

}

void Program::Render()
{
	Device::GetInstance()->Clear();


    _view->SetVS_Buffer(1);
    _proj->SetVS_Buffer(2);


    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();


    ADDITIVE->SetState();
	_curscene->Render();



    ImGui::Text("FPS : %d", FPS);
    ImGui::Text("DeltaTime : %1f", DELTA_TIME);
    ImGui::Text("RunTime : %1f", RUN_TIME);
    _curscene->PostRender();
    


    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();

}
