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
#include <memory>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <wrl/client.h> // 스마트포인터 사용을 위함


#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include "../DxTex/DirectXTex.h"

using namespace std;
using namespace DirectX;
using namespace Microsoft::WRL;


// Framework
#include "Framework/Device/Device.h"

// Math
#include "Framework/Math/Vector2.h"
#include "Framework/Math/Transform.h"

// Render
#include "Framework/Render/ConstantBuffer.h"
#include "Framework/Render/GlobalBuffer.h"
#include "Framework/Render/VertexLayout.h"
#include "Framework/Render/VertexBuffer.h"
#include "Framework/Render/IndexBuffer.h"
#include "Framework/Render/VertexShader.h"
#include "Framework/Render/PixelShader.h"

// TextureMapping
#include "Framework/TextureMapping/SRV.h"
#include "Framework/TextureMapping/SamplerState.h"
#include "Framework/TextureMapping//BlendState.h"
#include "Framework/TextureMapping//StateManager.h"

// Object
#include "Object/BasicObject/Quad.h"

// Obj
#include "Object/Obj/Planet.h"

// DUN
#include "Object/Obj/DunGreed/DunBullet.h"
#include "Object/Obj/DunGreed/DunPlayer.h"
// Scene
#include "Scene/Scene.h"


// Program
#include "Program/Program.h"

#include "Types.h"

extern HWND hWnd;
extern Vector2 mousePos;