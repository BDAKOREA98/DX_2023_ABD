#pragma once
class VertexShader : public Shader
{
public:
		VertexShader(wstring path);
		~VertexShader();

		void CreateBlob(wstring path);
		void CreateInputLayout();
		void CreateVertexShader();

		void SetIAInputLayout();
		virtual void Set() override;

		

private:

	ComPtr<ID3D11VertexShader> _vs;
	ComPtr<ID3D11InputLayout> _inputLayout;


};

