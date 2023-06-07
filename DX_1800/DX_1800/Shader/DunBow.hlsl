
Texture2D resource : register(t0); // texture
SamplerState samp : register(s0); // sampler = 판박이아저씨들


struct PixelInput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
	float2 uv : UV;
};

float4 PS(PixelInput input) : SV_TARGET
{
	float2 resultUV;
	resultUV.x = input.uv.x;
	resultUV.y = input.uv.y;

	float4 color = resource.Sample(samp, resultUV);

	float sum = color.x + color.y + color.z;

	if (sum > 1.0)
	{
		color.w = 0.0f;
	}

	return color;
}
