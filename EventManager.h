#pragma once
#include "Singleton.h"

class CEventManager : public Singleton<CEventManager>
{
public:
	CEventManager();
	~CEventManager();

	void Init();
	void Update();
	void Release();

	SDL_Event g_Event;

	bool KeyProsess[9];
	

	int nKey;

	void InitKeyProsess();


	bool CheckCollition(SDL_Rect mask1, SDL_Rect mask2);
	bool CheckCollition_by_mouse(SDL_Rect mask);

};

#define g_EventManager CEventManager::GetInstance()
#define g_EventKey CEventManager::g_Event.key.keysym.sym