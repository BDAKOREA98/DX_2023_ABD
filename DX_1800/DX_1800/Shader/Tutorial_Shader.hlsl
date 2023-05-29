// 현재 여기쓰이는 언어는 C++과 다른언어임
// 그저 비슷할 뿐




// Symentic Name
// SV : system value
// 
// vertex buffer에서 포지션을 받은 후 리턴
// 받은 포지션을 SV_POSITION에 넣어줌 = vertexsader에 넣어줌
float4 VS(float4 pos : POSITION) : SV_POSITION 
{
	return pos;
}

// 받은 SV_POSITION을 PixelShader에 넣어줌
float4 PS() : SV_TARGET
{
	return float4(1.0f, 1.0f, 0.0f, 1.0f);
}