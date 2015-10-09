#include "stdafx.h"
#include "SceneManager.h"
#include "EventManager.h"


CEventManager::CEventManager()
{
	nKey = 9;
	InitKeyProsess();
}


CEventManager::~CEventManager()
{
}


void CEventManager::Init()
{
	SDL_Init(SDL_INIT_EVENTS);

}


void CEventManager::Update()
{
	SDL_PollEvent(&g_Event);
	if (g_Event.type == SDL_KEYDOWN)
	{
		switch (g_Event.key.keysym.sym)
		{
		case SDLK_F10:
			g_SceneManager->SetScene(1);
			break;
		case SDLK_F11:
			g_SceneManager->SetScene(2);
			break;

		case SDLK_ESCAPE:
			exit(0);
			break;

		case SDLK_1:
			KeyProsess[n1] = true;
			break;

		case SDLK_2:
			KeyProsess[n2] = true;
			break;

		case SDLK_3:
			KeyProsess[n3] = true;
			break;

		case SDLK_4:
			KeyProsess[n4] = true;
			break;

		default:
			break;
		}
		if (g_EventKey == SDLK_UP)
		{
			KeyProsess[Up] = true;
		}
		if (g_EventKey == SDLK_DOWN)
		{
			KeyProsess[Down] = true;
		}
		if (g_EventKey == SDLK_LEFT)
		{
			KeyProsess[Left] = true;
		}
		if (g_EventKey == SDLK_RIGHT)
		{
			KeyProsess[Right] = true;
		}
		if (g_EventKey == SDLK_SPACE)
		{
			KeyProsess[Space] = true;
		}
	}
	else if (g_Event.type == SDL_QUIT)
	{
		exit(0);
	}
	else
	{
		InitKeyProsess();
	}
	SDL_FlushEvents(1073741881, 1073742106);
}


void CEventManager::Release()
{

}


void CEventManager::InitKeyProsess()
{
	for (int i = 0; i < nKey; i++)
	{
		KeyProsess[i] = false;
	}
}


bool CEventManager::CheckCollition(SDL_Rect mask1, SDL_Rect mask2)
{
	if ((mask1.x <= mask2.x || mask1.x <= mask2.x + mask2.w) && mask1.x + mask1.w >= mask2.x)
	{
		if ((mask1.y <= mask2.y || mask1.y <= mask2.y + mask2.h) && mask1.y + mask1.h >= mask2.y)
		{
			//printf("Ãæµ¹");
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool CEventManager::CheckCollition_by_mouse(SDL_Rect mask)
{
	if (g_Event.motion.x >= mask.x && g_Event.motion.x <= mask.x + mask.w)
	{
		if (g_Event.motion.y >= mask.y && g_Event.motion.y <= mask.y + mask.h)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}