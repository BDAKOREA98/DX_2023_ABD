﻿// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <math.h>
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>



using namespace std;
// math
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Collider.h"
#include "Math/CircleCollider.h"
#include "Math/RectCollider.h"
#include "Math/Line.h"

#include "Type.h"

//Object 폴더
#include "Object/Bullet.h"
#include "Object/Cannon.h"
#include "Object/Maze/MazeBlock.h"
#include "Object/Maze/Maze.h"

//Scene 폴더
#include "Scene/Scene.h"
// program 폴더
#include"Program/Program.h"


extern Vector2 mousePos;
extern HWND hWnd;

