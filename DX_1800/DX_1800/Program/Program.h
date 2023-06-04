#pragma once
class Program
{
public:
	Program();
	~Program();

	void Update();
	void Render();




private:

	shared_ptr<Scene> _curscene;
	shared_ptr<MatrixBuffer> _view;
	shared_ptr<MatrixBuffer> _proj;

};

