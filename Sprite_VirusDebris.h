#pragma once
#include "Sprite.h"
class CSprite_VirusDebris :
	public CSprite
{
public:
	CSprite_VirusDebris();
	CSprite_VirusDebris(CSprite *);
	~CSprite_VirusDebris();

	virtual void Update() override;
};

