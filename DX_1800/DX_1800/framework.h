// header.h: 표준 시스템 포함 파일
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
#include <functional> // 객체없이 함수포인터 사용을 위함
#include <time.h>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
// DirectX Tex
#include "../DxTex/DirectXTex.h"

//Imgui
#include "../Imgui/imgui.h"
#include "../Imgui/imgui_impl_win32.h"
#include "../Imgui/imgui_impl_dx11.h"


using namespace std;
using namespace DirectX;
using namespace Microsoft::WRL;


// Framework
#include "Framework/Device/Device.h"

// Math
#include "Framework/Math/Vector2.h"
#include "Framework/Math/Transform.h"

// Utility
#include "Framework/Utility/Timer.h"
#include "Framework/Utility/InputManager.h"
#include "Framework/Utility/tinyxml2.h"


// Render
#include "Framework/Render/ConstantBuffer.h"
#include "Framework/Render/GlobalBuffer.h"
#include "Framework/Render/VertexLayout.h"
#include "Framework/Render/VertexBuffer.h"
#include "Framework/Render/IndexBuffer.h"
#include "Framework/Render/Shader.h"
#include "Framework/Render/VertexShader.h"
#include "Framework/Render/PixelShader.h"
#include "Framework//Render/ShaderManager.h"

// TextureMapping
#include "Framework/TextureMapping/SRV.h"
#include "Framework/TextureMapping/SRVManager.h"
#include "Framework/TextureMapping/SamplerState.h"
#include "Framework/TextureMapping//BlendState.h"
#include "Framework/TextureMapping//StateManager.h"


//Action
#include "Framework/Animation/Action.h"

// Object
#include "Object/BasicObject/Quad.h"
#include "Object/BasicObject/Sprite.h"
#include "Object/BasicObject/Sprite_Clip.h"
#include "Object/BasicObject/Sprite_Frame.h"

// Collider
#include "Framework/Collider/Collider.h"
#include "Framework/Collider/RectCollider.h"
#include "Framework/Collider/CircleCollider.h"

// CupHead
#include "Object/Obj/CupHead/CupHead.h"
#include "Object/Obj/CupHead/player.h"

// Obj
#include "Object/Obj/Planet.h"

// DUN
#include "Object/Obj/DunGreed/DunBullet.h"
#include "Object/Obj/DunGreed/DunBow.h"
#include "Object/Obj/DunGreed/DunPlayer.h"
#include "Object/Obj/DunGreed/DunMob.h"
// Scene
#include "Scene/Scene.h"


// Program
#include "Program/Program.h"
#include "Types.h"


extern HWND hWnd;
