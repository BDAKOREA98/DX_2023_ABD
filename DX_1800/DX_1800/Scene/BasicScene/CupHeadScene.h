#pragma once
class CupHeadScene : public Scene
{

public:
		CupHeadScene();
		virtual ~CupHeadScene();


	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;

	virtual void Render() override;
	virtual void PostRender() override;



private:
	shared_ptr<class CupHead> _cup;
	

};
