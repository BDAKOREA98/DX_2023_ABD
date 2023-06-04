#include "framework.h"
#include "Program.h"

#include "../Scene/BasicScene/TutorialScene.h"
#include "../Scene/BasicScene/SolarSystem.h"
#include "../Scene/BasicScene/DunGreed.h"

Program::Program()
{
	_curscene = make_shared<DunGreed>();

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
	_curscene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();


    _view->SetVS_Buffer(1);
    _proj->SetVS_Buffer(2);

    ALPHA->SetState();
	_curscene->Render();

	Device::GetInstance()->Present();

}
