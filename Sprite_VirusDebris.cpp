#include "stdafx.h"
#include "Sprite_VirusDebris.h"


CSprite_VirusDebris::CSprite_VirusDebris() : CSprite("VirusDebris", 25, 25, 100, 100, 65, 65)
{
	SetSpriteImage("./Resource/Virus_Debris.png");

	SpriteRect.x = rand() % (WINDOW_DEFAULT_W - 200) + 100;
	SpriteRect.y = rand() % (WINDOW_DEFAULT_H - 200) + 100;
}

CSprite_VirusDebris::CSprite_VirusDebris(CSprite * sprite) : CSprite("VirusDebris", 25, 25, 100, 100, 65, 65)
{
	SetSpriteImage("./Resource/Virus_Debris.png");

	SpriteRect.x = sprite->GetSpriteRect()->x;
	SpriteRect.y = sprite->GetSpriteRect()->y;
}


CSprite_VirusDebris::~CSprite_VirusDebris()
{
}


void CSprite_VirusDebris::Update()
{


}

