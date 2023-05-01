#include "framework.h"
#include "Scene/PaintScene.h"
#include "Scene/LineScene.h"
#include "Scene/LineCollisionScene.h"
#include "Scene/CannonScene.h"
#include "Scene/MazeScene.h"
#include "Program.h"


HDC Program::_backBuffer = nullptr; // 정적변수는 초기화 필 수 
Program::Program()
{

	// hWnd : 윈도우 핸들 윈도우를 수정하거나 기타 등등에 필요한 것
	HDC hdc = GetDC(hWnd);
	_backBuffer = CreateCompatibleDC(hdc);
	_hbit = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
	SelectObject(_backBuffer, _hbit);
	// 씬변경
	_scene = make_shared<MazeScene>();
}

Program::~Program()
{
	DeleteObject(_backBuffer);
	DeleteObject(_hbit);

}

void Program::Update()
{
	_scene->Update();
}

void Program::Render(HDC hdc)
{
	PatBlt(_backBuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, BLACKNESS);

	_scene->Render(_backBuffer);

	BitBlt( // 백버퍼를 복사 하겠다. 
		hdc, // 매개변수 hdc
		0, 0, WIN_WIDTH, WIN_HEIGHT, // 윈도우 WIDTH와 HEIGHT만큼 복사하겠다.
		_backBuffer, 0, 0, // 백버퍼에 그려놓은것을
		SRCCOPY

	);
}
