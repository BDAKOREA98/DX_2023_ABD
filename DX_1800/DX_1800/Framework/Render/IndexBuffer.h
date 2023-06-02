#pragma once
class IndexBuffer
{

public:
	IndexBuffer(void* data, UINT count);
	~IndexBuffer();

	void SetIA_IndexBuffer();
	void CreateIndexBuffer(void* data);


private:
	ComPtr<ID3D11Buffer> _indexbuffer;
	UINT _count;


};

