#pragma once
class Vector2
{
public:
    Vector2()
        : x(0), y(0)
    {
    }
    Vector2(int x, int y)
        : x((float)x), y((float)y) // - float 으로 C스타일 형변환
    {
        //  * this
        // this->x = x;
    }

    Vector2(float x, float y)
        : x(x), y(y)
    {

    }

    // 복사대입 생성자
    Vector2(const Vector2& other) 
        : x(other.x), y(other.y)
    {
      
    }
    // 벡터의 덧셈 연산자 오버로딩
    Vector2 operator+(const Vector2& other) const
    {
        Vector2 result;
        result.x = (*this).x + other.x;
        result.y = this->y + other.y;

        return result;
    }

    Vector2 operator-(const Vector2& other) const
    {
        Vector2 result;
        result.x = (*this).x - other.x;
        result.y = this->y - other.y;
        return result;
    }

    Vector2 operator*(const float& value) const
    {
        Vector2 result;
        return result = Vector2(this->x * value, this->y * value);
    }
    // 복사대입연산자 - 암시적으로 생성되는 연산자
    // a = b : a에다 b를 대입하고, a의 원본을 반환한다.
    Vector2& operator=(const Vector2& other)
    {
       
        x = other.x;
        y = other.y;

        return *this;
    }

    Vector2& operator+=(const Vector2 other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;

    // 길이
    // 스칼라 : 힘 또는 길이 /  벡터 : 길이, 방향
    float Length() const // 뒤에 있는 const는 함수 내부에서 멤버변수를 건드리지 마라.
    {
        float result = sqrtf(x * x + y * y);

        return result;
    }

   /* float Direction(const Vector2& other) const
    {
        Vector2 result;
        result = 

    }*/

    float Distance(const Vector2& other) const // 두 벡터의 거리
    {
        Vector2 result = *this - other;
        return result.Length();
    }

    float Dot(const Vector2& other) const // 두 벡터의 내적
    {
        float result = x * other.x + y * other.y;
        return result;
    }

    float Cross(const Vector2& other) const 
    {
        float result = x * other.y - other.x * y;

        return result;
    }

    

    float Angle() const
    {
        
           float result = atan2f(y, x);
        return result;
    }

    Vector2 NorMalVector2() const // 단위벡터를 뽑기위한 식
    {
        Vector2 result;
        result.x = x / Length();
        result.y = y / Length();

        return result;
    }

    void Normalize() // 단위 벡터를 뽑아내는 식
    {
        x /= Length();
        y /= Length();
    }

    bool IsBetween(Vector2 a, Vector2 b);


public:
    float x = 0.0f;
    float y = 0.0f;
};