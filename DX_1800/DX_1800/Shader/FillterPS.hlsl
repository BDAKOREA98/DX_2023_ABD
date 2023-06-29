Texture2D resource : register(t0);
SamplerState samp : register(s0);

cbuffer FilterBuffer : register(b0)
{
	int selected;
	int value1;
	int value2;
	int value3;

	float2 imageSize;
	float2 radialCenter;
}

struct PixelInput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
	float2 uv : UV;
};

float4 Mosaic(float2 uv)
{
	// 0 ~ 1 * 10 .. 0.5 => 5 , 0.55 => 5
	float x = floor(uv.x * value1); // floor : 소수뒷자리 날리는 함수
	float y = floor(uv.y * value1);

	float2 temp;
	temp.x = x / value1; // uv == 0.5일 경우 0.5가 나옴   0.55일경우도 0.5
	temp.y = y / value1;
	// temp 
	return resource.Sample(samp, temp);
}

float4 Blur(float2 uv)
{
	float4 result = 0;

	if (value2 == 0)
	{
		return resource.Sample(samp, uv);

	}

	for (int i = 0; i < value2; i++)
	{
		float divX = (i + 1) / imageSize.x;
		float divY = (i + 1) / imageSize.y;

		result += resource.Sample(samp, float2(uv.x + divX, uv.y));
		result += resource.Sample(samp, float2(uv.x - divX, uv.y));
		result += resource.Sample(samp, float2(uv.x , uv.y + divY));
		result += resource.Sample(samp, float2(uv.x , uv.y - divY));
	}

	result /= 4 * value2;

	return result;

}

float4 OctaBlur(float2 uv)
{
	float4 result = 0;

	if (value2 == 0)
	{
		return resource.Sample(samp, uv);

	}

	for (int i = 0; i < value2; i++)
	{
		float divX = (i + 1) / imageSize.x;
		float divY = (i + 1) / imageSize.y;

		result += resource.Sample(samp, float2(uv.x + divX, uv.y));
		result += resource.Sample(samp, float2(uv.x - divX, uv.y));
		result += resource.Sample(samp, float2(uv.x, uv.y + divY));
		result += resource.Sample(samp, float2(uv.x, uv.y - divY));

		result += resource.Sample(samp, float2(uv.x + divX, uv.y + divY));
		result += resource.Sample(samp, float2(uv.x - divX, uv.y + divY));
		result += resource.Sample(samp, float2(uv.x + divX, uv.y - divY));
		result += resource.Sample(samp, float2(uv.x - divX, uv.y - divY));
	}

	result /= 8 * value2;

	return result;

}

float4 PS(PixelInput input) : SV_TARGET
{

	// shader에서 리턴은 branch를 붙이면 최적하가 됨
	[branch]
	if (selected == 0)
	{
		return resource.Sample(samp, input.uv);
	}
	else if (selected == 1)
	{
		return Mosaic(input.uv);
	}
	else if (selected == 2)
	{
		return Blur(input.uv);
	}
	else if (selected == 3)
	{
		return OctaBlur(input.uv);
	}

	return resource.Sample(samp, input.uv);
}