#pragma once
class SRV
{

public:

	SRV(wstring path);
	~SRV();

	void SetSRV(UINT slot);

private:
	ComPtr<ID3D11ShaderResourceView> srv;
};

