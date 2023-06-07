#pragma once
class Vector3
{
public:
	Vector3 operator+ (const Vector3& P2) const
	{
			Vector3 temp;
			temp.x = this->x + P2.x,
			temp.y = this->y + P2.y,
			temp.z = this->z + P2.z;
			return temp;
	}
	Vector3 operator- (const Vector3& P2) const
	{
			Vector3 temp;
			temp.x = this->x - P2.x,
			temp.y = this->y - P2.y,
			temp.z = this->z - P2.z;
			return temp;
	}



private:

	float x;
	float y;
	float z;
	
};

