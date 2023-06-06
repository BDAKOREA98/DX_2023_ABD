#include "framework.h"
#include "Transform.h"

Transform::Transform()
{

	_world = make_shared<MatrixBuffer>();
}

Transform::~Transform()
{
}

void Transform::Update()
{
    Update_SRT();
    Update_WorldBuffer();
    
}

void Transform::Update_WorldBuffer()
{
	
    _world->SetData(_srtMatrix);
    _world->Update_Resource();
}

void Transform::Update_SRT()
{

    _scaleM = XMMatrixScaling(_scale.x, _scale.y, 1.0f);
    _rotateM = XMMatrixRotationZ(_angle);
    _translateM = XMMatrixTranslation(_pos.x, _pos.y, 0);

    _srtMatrix = _scaleM * _rotateM * _translateM;

    if (_parent.expired() == false)
    {               // 행렬의 뒤에다가 곱해준다 == 행렬의 종속이다.
        _srtMatrix *= _parent.lock()->GetSRT();

    }

}

void Transform::SetWorldBuffer(UINT slot)
{

    _world->SetVS_Buffer(slot);

   
}
Vector2 Transform::GetWorldPos() const
{
    XMFLOAT4X4 temp;

    XMStoreFloat4x4(&temp, _srtMatrix);


    // 이동 행렬의 위치는 4-1, 4-2이므로 41,42
    return Vector2(temp._41, temp._42);
}

Vector2 Transform::GetWorldScale() const
{
    XMFLOAT4X4 temp;

    XMStoreFloat4x4(&temp, _srtMatrix);

    if (_parent.expired() == false)
    {
        Vector2 parentScale = _parent.lock()->GetWorldScale();
        return Vector2(temp._11 * parentScale.x, temp._22 * parentScale.y);
    }

    return Vector2(temp._11, temp._22);
}

