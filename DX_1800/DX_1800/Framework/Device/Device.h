#pragma once

// Device는 여러개가 필요없기에 싱글턴으로 만듦
// 싱글턴은 스마트 포인터를 지양함 이유는 원할때 생성하고 원할때 삭제해야하기에

class Device
{

private:

	Device();
	~Device();


public:
	static void Create()
	{
		if (_instance == nullptr)
		{
			_instance = new Device();
		}

	}
	static void Delete()
	{
		if (_instance != nullptr)
		{
			delete _instance;
		}

	}
	static Device* GetInstance()
	{
		if (_instance != nullptr)
		{
			return _instance;
		}

		return nullptr;
	}

	ComPtr<ID3D11Device> GetDevice() { return device; }
	ComPtr<ID3D11DeviceContext> GetDC() { return deviceContext; }

	void Clear();
	void Present();

private:
	static Device* _instance;

	void CreateDeviceAndSwapChain();
	void CreateDoubleBuffer();

	ComPtr<ID3D11Device> device; 
	ComPtr<ID3D11DeviceContext> deviceContext; 
	ComPtr<IDXGISwapChain> swapChain;
	ComPtr<ID3D11RenderTargetView> renderTargetView;

};

