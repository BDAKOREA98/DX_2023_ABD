#pragma once
class DunGreed : public Scene
{
public:
	DunGreed();
	virtual ~DunGreed();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<DunPlayer> _player;
	shared_ptr<Transform> _playertrans;

	

	
	//shared_ptr<Transform> _mobtrans;

};

