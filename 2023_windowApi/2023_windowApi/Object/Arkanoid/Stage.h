#pragma once
class Stage
{
public:
	Stage();
	~Stage();

	void Update();
	void Render(HDC hdc);

private:

	shared_ptr<Collider> _stage;
	vector<HBRUSH> _brushes;


};

