#include "stdafx.h"

#include "EventManager.h"

#include "Sprite.h"
#include "Sprite_Player.h"


CSprite_Player::CSprite_Player() : CSprite("Player", 29, 67, 100, 100, 29, 67)
{
	SetSpriteImage("./Resource/player.png");
	bIsMove = true;
}


CSprite_Player::~CSprite_Player()
{
}


void CSprite_Player::Update()
{
	SpriteMask = SpriteRect;

	if (g_EventManager->g_Event.type == SDL_KEYDOWN)
	{
		if (g_EventManager->KeyProsess[Left] == true && bIsMove)
		{
			SetSpriteX(GetSpriteX() - 5);
			SpriteDir = cLEFT;
		}
		if (g_EventManager->KeyProsess[Right] == true && bIsMove)
		{
			SetSpriteX(GetSpriteX() + 5);
			SpriteDir = cRIGHT;
		}
		if (g_EventManager->KeyProsess[Up] == true && bIsMove)
		{
			SetSpriteY(GetSpriteY() - 5);
			SpriteDir = cUP;
		}
		if (g_EventManager->KeyProsess[Down] == true && bIsMove)
		{
			SetSpriteY(GetSpriteY() + 5);
			SpriteDir = cDOWN;
		}
		if (g_EventManager->KeyProsess[Space] == true && bIsMove)
		{
			SetSpriteX(100);
			SetSpriteY(100);
		}
		g_EventManager->InitKeyProsess();
	}
}

void CSprite_Player::SetPlayerbIsMove(bool b)
{
	this->bIsMove = b;
}

bool* CSprite_Player::GetPlayerbIsMove()
{
	return &bIsMove;
}
