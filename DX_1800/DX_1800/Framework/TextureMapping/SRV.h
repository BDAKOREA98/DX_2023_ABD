#pragma once
class SRV
{

public:

	SRV(wstring path);
	~SRV();



	void SetSRV(UINT slot);

	Vector2 GetImageze() { return _imageSize; }


private:

	Vector2 _imageSize;

	ComPtr<ID3D11ShaderResourceView> _srv;
};

