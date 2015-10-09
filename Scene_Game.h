#pragma once
#include "Scene.h"
class CScene_Game : public CScene
{
public:
	CScene_Game();
	~CScene_Game();

	void CreateVirus();

private:
	clock_t VirusCreateTime;
	int VirusCode;				//���� ���̷��� ���ط� ������ ���̷���.

	int Vaccine_Usable;			//����� ����� �� �ִ� ī��Ʈ ����.
	
	int Virus_Debris_Count;		//���� ���̷��� ���� ��
	int Virus_Debris_Eaten;		//���� ���̷��� ��
	char Virus_Debris_Text[2][100];
	int Virus_Debris_Text_idx[2];


	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
};
