#include "stdafx.h"
#include "Sprite_Virus.h"


CSprite_Virus::CSprite_Virus(int _code) : CSprite("Virus", 25, 25, 100, 100, 65, 65)
{
	Code = _code;
	switch (Code)
	{
	case RED:
		SetSpriteImage("./Resource/Red_Virus.png");
		break;

	case BLUE:
		SetSpriteImage("./Resource/Blue_Virus.png");
		break;

	case GREEN:
		SetSpriteImage("./Resource/Green_Virus.png");
		break;

	case YELLOW:
		SetSpriteImage("./Resource/Yellow_Virus.png");
		break;

	default:
		break;
	}
	SpriteRect.x = rand() % (WINDOW_DEFAULT_W - 200) + 100;
	SpriteRect.y = rand() % (WINDOW_DEFAULT_H - 200) + 100;

	SetSpriteCenter(20, 25);
}


CSprite_Virus::~CSprite_Virus()
{
}


bool CSprite_Virus::CheckCode(int zCode)
{
	if (zCode == Code)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void CSprite_Virus::Update()
{
	if (rotation <= 360)
	{
		rotation += 0.5;
	}
	else
	{
		rotation = 0;
	}
}

