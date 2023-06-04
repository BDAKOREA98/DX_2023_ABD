#pragma once
class SolarSystem : public Scene
{

public:
	SolarSystem();
	virtual ~SolarSystem();


	// Scene을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;

private:

	shared_ptr<BlendState> _BlendState;

	shared_ptr<Planet> _sun;
	shared_ptr<Planet> _earth;
	shared_ptr<Planet> _moon;



};

