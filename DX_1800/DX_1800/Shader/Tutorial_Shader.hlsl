// 현재 여기쓰이는 언어는 C++과 다른언어임
// 그저 비슷할 뿐


struct VertexInput
{
	float4 pos : POSITION;
	float4 color : COLOR;
};

struct VertexOutput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
};



// Symentic Name
// SV : system value
// 
// vertex buffer에서 포지션을 받은 후 리턴
// 받은 포지션을 SV_POSITION에 넣어줌 = vertexsader에 넣어줌
VertexOutput VS(VertexInput input)
{
	VertexOutput result;
	result.pos = input.pos;
	result.color = input.color;

	return result;
}

// 받은 SV_POSITION을 PixelShader에 넣어줌
float4 PS(VertexOutput input) : SV_TARGET
{
	return input.color;
}