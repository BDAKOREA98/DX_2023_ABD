
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

	return resource.Sample(samp, resultUV);
}
