#include "stdafx.h"

#include "EventManager.h"

#include "Sprite.h"
#include "Sprite_Player.h"


CSprite_Player::CSprite_Player() : CSprite("Player", 29, 67, 100, 100, 29, 67)
{
	SetSpriteImage("./Resource/player.png");
}


CSprite_Player::~CSprite_Player()
{
}


void CSprite_Player::Update()
{
	SpriteMask = SpriteRect;

	if (g_EventManager->g_Event.type == SDL_KEYDOWN)
	{
		if (g_EventManager->KeyProsess[Left] == true)
		{
			SetSpriteX(GetSpriteX() - 5);
		}
		if (g_EventManager->KeyProsess[Right] == true)
		{
			SetSpriteX(GetSpriteX() + 5);
		}
		if (g_EventManager->KeyProsess[Up] == true)
		{
			SetSpriteY(GetSpriteY() - 5);
		}
		if (g_EventManager->KeyProsess[Down] == true)
		{
			SetSpriteY(GetSpriteY() + 5);
		}
		if (g_EventManager->KeyProsess[Space] == true)
		{
			SetSpriteX(100);
			SetSpriteY(100);
		}
		g_EventManager->InitKeyProsess();
	}
}

