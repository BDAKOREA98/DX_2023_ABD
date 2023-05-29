// ���� ���⾲�̴� ���� C++�� �ٸ������
// ���� ����� ��


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
// vertex buffer���� �������� ���� �� ����
// ���� �������� SV_POSITION�� �־��� = vertexsader�� �־���
VertexOutput VS(VertexInput input)
{
	VertexOutput result;
	result.pos = input.pos;
	result.color = input.color;

	return result;
}

// ���� SV_POSITION�� PixelShader�� �־���
float4 PS(VertexOutput input) : SV_TARGET
{
	return input.color;
}