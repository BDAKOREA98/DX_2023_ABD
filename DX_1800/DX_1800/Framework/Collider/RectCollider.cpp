#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector2 size)
: _size(size)
{
	CreateVertices();
	CreateData();

    _type = Type::RECT;
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
    _transform->Update();

    _colorBuffer->SetColor(_color);
    _colorBuffer->Update_Resource();
}

void RectCollider::Render()
{
    _transform->SetWorldBuffer(0);
    _colorBuffer->SetPS_Buffer(0);

    _vertexBuffer->SetIA_VertexBuffer();
    _vs->SetIAInputLayout();

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

    _vs->Set_VS();
    _ps->Set_PS();

    DC->Draw(_vertices.size(),0);
}

void RectCollider::CreateVertices()
{
    Vertex v;

    Vector2 halfSize = _size * 0.5f;

    v.pos = { -halfSize.x, halfSize.y, 0.0f }; // 왼쪽 위
    _vertices.push_back(v);

    v.pos = { halfSize.x, halfSize.y, 0.0f }; // 오른쪽 위
    _vertices.push_back(v);

    v.pos = { halfSize.x, -halfSize.y, 0.0f }; // 오른쪽 아래
    _vertices.push_back(v);

    v.pos = { -halfSize.x, -halfSize.y, 0.0f }; // 왼쪽 아래
    _vertices.push_back(v);

    v.pos = { -halfSize.x, halfSize.y, 0.0f }; // 왼쪽 위
    _vertices.push_back(v);
}

void RectCollider::CreateData()
{
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
    _colorBuffer = make_shared<ColorBuffer>();

    _vs = make_shared<VertexShader>(L"Shader/ColliderVS.hlsl");
    _ps = make_shared<PixelShader>(L"Shader/ColliderPS.hlsl");
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> col)
{
    AABB_Info info = GetAABB_Info();

    Vector2 circleWorldPos = col->GetWorldPos();

    float circleLeft         = circleWorldPos.x - col->GetWorldRadius();
    float circleRight        = circleWorldPos.x + col->GetWorldRadius();
    float circleTop          = circleWorldPos.y + col->GetWorldRadius();
    float circleBottom       = circleWorldPos.y - col->GetWorldRadius();

    if (circleWorldPos.x < info.right && circleWorldPos.x > info.left)
    {
        if (circleBottom < info.top && circleTop > info.bottom)
        {
            return true;
        }
    }

    //_rectCollider = make_shared<RectCollider>(Vector2(90, 150));
    //_rectCollider2 = make_shared<RectCollider>(Vector2(40, 70));

    if (circleWorldPos.y > info.bottom && circleWorldPos.y < info.top)
    {
        if (circleLeft < info.right && circleRight > info.left)
        {
            return true;
        }
    }

    if (col->IsCollision(Vector2(info.left, info.top))
        || col->IsCollision(Vector2(info.right, info.top))
        || col->IsCollision(Vector2(info.left, info.bottom))
        || col->IsCollision(Vector2(info.right, info.bottom)))
    {
        return true;
    }

    return false;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> col)
{
    AABB_Info aInfo = GetAABB_Info();
    AABB_Info bInfo = col->GetAABB_Info();

    if (aInfo.left > bInfo.right || aInfo.right < bInfo.left
        || aInfo.top < bInfo.bottom || aInfo.bottom > bInfo.top)
        return false;

    return true;
}

bool RectCollider::IsOBB(shared_ptr<RectCollider> col)
{
    OBB_Info aInfo = GetOBB_info();
    OBB_Info bInfo = col->GetOBB_info();

    Vector2 aTob = aInfo.pos - bInfo.pos;
    
    Vector2 nea1 = aInfo.direction[0];
    Vector2 nea2 = aInfo.direction[1];
    Vector2 ea1 = nea1 * aInfo.length[0];
    Vector2 ea2 = nea1 * aInfo.length[1];

    Vector2 neb1 = bInfo.direction[0];
    Vector2 neb2 = bInfo.direction[1];
    Vector2 eb1 = neb1 * bInfo.length[0];
    Vector2 eb2 = neb1 * bInfo.length[1];


    // nea1 기준으로 투영
    float length = abs(nea1.Dot(aTob));
    float lengthA = ea1.Length();
    float lengthB = SeperateAxis(nea1, eb1, eb2);

    if (length > lengthA + lengthB)
    {
        return false;
    }
    // nea2

    length = abs(nea2.Dot(aTob));
    lengthA = ea2.Length();
    lengthB = SeperateAxis(nea2, eb1, eb2);

    if (length > lengthA + lengthB)
    {
        return false;
    }
    // neb1
    length = abs(neb1.Dot(aTob));
    lengthA = eb1.Length();
    lengthB = SeperateAxis(neb1, ea1, ea2);

    if (length > lengthA + lengthB)
    {
        return false;
    }
    // neb2
    length = abs(neb2.Dot(aTob));
    lengthA = eb2.Length();
    lengthB = SeperateAxis(neb1, ea1, ea2);

    if (length > lengthA + lengthB)
    {
        return false;
    }

    return true;
}

float RectCollider::SeperateAxis(Vector2 separate, Vector2 e1, Vector2 e2)
{
    float r1 = abs(separate.Dot(e1));
    float r2 = abs(separate.Dot(e2));


    return r1 + r2;
}

void RectCollider::SetScale(Vector2 scale)
{
    _transform->SetScale(scale);
    _size.x *= scale.x;
    _size.y *= scale.y;
}

RectCollider::AABB_Info RectCollider::GetAABB_Info()
{
    AABB_Info info;
    Vector2 worldPos = _transform->GetWorldPos();
    Vector2 worldScale = _transform->GetWorldScale();

    info.left =      _transform->GetWorldPos().x - _size.x * worldScale.x * 0.5f;
    info.right =     _transform->GetWorldPos().x + _size.x * worldScale.x * 0.5f;
    info.top =       _transform->GetWorldPos().y + _size.y * worldScale.y * 0.5f;
    info.bottom =    _transform->GetWorldPos().y - _size.y * worldScale.y * 0.5f;

    return info;
}

RectCollider::OBB_Info RectCollider::GetOBB_info()
{
    OBB_Info info;
    Vector2 halfsize = _size * 0.5f;
    XMFLOAT4X4 matrix;
    // GetSrT로는 1,1 지점을 찾을 수 없기에 매트릭스에 집어넣어서 찾는과정임
    XMStoreFloat4x4(&matrix, _transform->GetSRT());
    info.pos = _transform->GetWorldPos();
    //방향 집어넣기
    info.direction[0] = { matrix._11, matrix._12 };
    info.direction[1] = { matrix._21, matrix._22 };

    // 단위 벡터 찾기
    info.direction[0].Normalize();
    info.direction[1].Normalize();

    

    // 원하는 벡터 크기찾기
    info.length[0] = halfsize.x * _transform->GetWorldScale().x;
    info.length[1] = halfsize.y * _transform->GetWorldScale().y;



    return info;
}

bool RectCollider::IsCollision(const Vector2& pos)
{
    AABB_Info info = GetAABB_Info();

    if (pos.x > info.left && pos.x < info.right)
    {
        if (pos.y > info.bottom && pos.y < info.top)
            return true;
    }
    return false;
}
