#pragma once
// 상수버퍼
// GPU가 쓸때 바꾸지 못 하고 읽기만 가능하다.
class ConstantBuffer
{
public:
	ConstantBuffer(void* data, UINT datasize);
	~ConstantBuffer();
	
	void Update_Resource();
	void SetVS_Buffer(UINT slot);
	void SetPS_Buffer(UINT slot);


private:

	ComPtr<ID3D11Buffer> _constantBuffer;

	void* _data;

	UINT _datasize;

};

