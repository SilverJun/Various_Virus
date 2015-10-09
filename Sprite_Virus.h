#pragma once
#include "Sprite.h"

enum {RED = 0, BLUE, GREEN, YELLOW};

class CSprite_Virus : public CSprite
{
private:
	static int nVirus;
	int Code;	//바이러스 종류

public:
	CSprite_Virus(int);
	~CSprite_Virus();
	
	bool CheckCode(int);
	virtual void Update()override;
};

