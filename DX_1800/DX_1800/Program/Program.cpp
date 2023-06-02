#include "framework.h"
#include "Program.h"

#include "../Scene/BasicScene/TutorialScene.h"

Program::Program()
{
	_curscene = make_shared<TutorialScene>();
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

	_curscene->Render();

	Device::GetInstance()->Present();

}
