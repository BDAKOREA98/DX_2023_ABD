
Texture2D resource : register(t0); // texture
SamplerState samp : register(s0); // sampler = 판박이아저씨들

cbuffer FrameBuffer : register(b0)
{
	float2 maxFrame;
	float2 curFrame;
};


struct PixelInput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
	float2 uv : UV;
};

float4 PS(PixelInput input) : SV_TARGET
{
	float2 resultUV;
	
		// cur == (0,1)
		// maxFrmae = (10,8)
		// input = (0,0)
		// reusltUV.x = 0
		// reusltUV.y = 1/8
						// 0 /  10+0 / 10 == 0 / 10 + 0 / 10 
						// 0 /  8 + 1 / 8 == 0 / 8 + 1/ 8 == 1/8
						// resultUV.x = 0
						// resultUV.y = 1/8
						// 
	resultUV.x = input.uv.x  / maxFrame.x + curFrame.x / maxFrame.x;
	resultUV.y = input.uv.y / maxFrame.y + curFrame.y / maxFrame.y;

	return resource.Sample(samp, resultUV);
}
