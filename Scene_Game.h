#pragma once
#include "Scene.h"
#include "VirusPattern.h"


class CScene_Game : public CScene
{
public:
	CScene_Game();
	~CScene_Game();

	void CreateVirus();

private:
	clock_t VirusCreateTime;
	int VirusCode;				//현재 바이러스 잔해로 나오는 바이러스.

	int Vaccine_Usable;			//백신을 사용할 수 있는 카운트 단위.
	
	int Virus_Debris_Count;		//현재 바이러스 잔해 수
	int Virus_Debris_Eaten;		//먹은 바이러스 수
	char Virus_Debris_Text[2][120];
	int Virus_Debris_Text_idx[2];

	VirusPattern *Pattern;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
};

