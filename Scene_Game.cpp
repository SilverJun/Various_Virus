#include "stdafx.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "TextManager.h"
#include "Scene_Game.h"


#include "Sprite_Player.h"
#include "Sprite_Virus.h"
#include "Sprite_VirusDebris.h"

CScene_Game::CScene_Game() : CScene(2)
{
	addSprite(new CSprite_Player());
	VirusCreateTime = 800;
	VirusCode = RED;
	Virus_Debris_Count = 0;
	Virus_Debris_Eaten = 0;
	Vaccine_Usable = 5;
}


CScene_Game::~CScene_Game()
{
	Release();
	g_TimeManager->Init(2);
}


void CScene_Game::CreateVirus()
{
	int code = rand() % 4;
	if (VirusCode == code)
	{
		addSprite(new CSprite_VirusDebris());
		Virus_Debris_Count++;
	}
	else
	{
		addSprite(new CSprite_Virus(code));
	}
}


void CScene_Game::Init()
{
	for (int i = 0; i < 10; i++)
	{
		CreateVirus();
	}

	sprintf(Virus_Debris_Text[0], "바이러스 잔해 수 : %d", Virus_Debris_Count);
	Virus_Debris_Text_idx[0] = g_TextManager->CreateText(Virus_Debris_Text[0], 10, 10, (strlen(Virus_Debris_Text[0]) - 1) * 20, 40);
	sprintf(Virus_Debris_Text[1], "먹은 바이러스 수 : %d", Virus_Debris_Count);
	Virus_Debris_Text_idx[1] = g_TextManager->CreateText(Virus_Debris_Text[1], 10, 50, (strlen(Virus_Debris_Text[1]) - 1) * 20, 40);
}


void CScene_Game::Update()
{
	clock_t TimeGap = g_TimeManager->GetTime(2)[CurTime] - g_TimeManager->GetTime(2)[OldTime];
	if (TimeGap > VirusCreateTime)
	{
		CreateVirus();

		g_TimeManager->Init(2);
		if (VirusCreateTime > 400)
		{
			VirusCreateTime -= 10;
		}
	}
	if (g_EventManager->g_Event.type == SDL_KEYDOWN)
	{

		if (g_EventManager->KeyProsess[n1] == true && Virus_Debris_Eaten >= Vaccine_Usable)
		{
			VirusCode = RED;
			
			for (int i = 0; i != nSprite; i++)
			{
				if (vSprite[i] != nullptr)
				{
					if (vSprite[i]->GetSpriteName() == "Virus")
					{
						if (static_cast<CSprite_Virus *>(vSprite[i])->CheckCode(VirusCode))
						{
							vSprite[i] = new CSprite_VirusDebris(vSprite[i]);
							Virus_Debris_Count++;
						}
						else
						{
							delete vSprite[i];
							vSprite[i] = nullptr;
						}
					}
				}
			}
			g_EventManager->KeyProsess[n1] = false;
			Virus_Debris_Eaten -= Vaccine_Usable;
			Vaccine_Usable += 5;
		}
		if (g_EventManager->KeyProsess[n2] == true && Virus_Debris_Eaten >= Vaccine_Usable)
		{
			VirusCode = BLUE;
			for (int i = 0; i != nSprite; i++)
			{
				if (vSprite[i] != nullptr)
				{
					if (vSprite[i]->GetSpriteName() == "Virus")
					{
						if (static_cast<CSprite_Virus *>(vSprite[i])->CheckCode(VirusCode))
						{
							vSprite[i] = new CSprite_VirusDebris(vSprite[i]);
							Virus_Debris_Count++;
						}
						else
						{
							delete vSprite[i];
							vSprite[i] = nullptr;
						}
					}
				}
			}
			g_EventManager->KeyProsess[n2] = false;
			Virus_Debris_Eaten -= Vaccine_Usable;
			Vaccine_Usable += 5;
		}
		if (g_EventManager->KeyProsess[n3] == true && Virus_Debris_Eaten >= Vaccine_Usable)
		{
			VirusCode = GREEN;
			for (int i = 0; i != nSprite; i++)
			{
				if (vSprite[i] != nullptr)
				{
					if (vSprite[i]->GetSpriteName() == "Virus")
					{
						if (static_cast<CSprite_Virus *>(vSprite[i])->CheckCode(VirusCode))
						{
							vSprite[i] = new CSprite_VirusDebris(vSprite[i]);
							Virus_Debris_Count++;
						}
						else
						{
							delete vSprite[i];
							vSprite[i] = nullptr;
						}
					}
				}
			}
			g_EventManager->KeyProsess[n3] = false;
			Virus_Debris_Eaten -= Vaccine_Usable;
			Vaccine_Usable += 5;
		}
		if (g_EventManager->KeyProsess[n4] == true && Virus_Debris_Eaten >= Vaccine_Usable)
		{
			VirusCode = YELLOW;
			for (int i = 0; i != nSprite; i++)
			{
				if (vSprite[i] != nullptr)
				{
					if (vSprite[i]->GetSpriteName() == "Virus")
					{
						if (static_cast<CSprite_Virus *>(vSprite[i])->CheckCode(VirusCode))
						{
							vSprite[i] = new CSprite_VirusDebris(vSprite[i]);
							Virus_Debris_Count++;
						}
						else
						{
							delete vSprite[i];
							vSprite[i] = nullptr;
						}
					}
				}
			}
			g_EventManager->KeyProsess[n4] = false;
			Virus_Debris_Eaten -= Vaccine_Usable;
			Vaccine_Usable += 5;
		}
	}

	

	for (int i = 1; i != nSprite; i++)
	{
		if (vSprite[i] != nullptr)
		{
			vSprite[i]->Update();
			if (vSprite[i]->GetSpriteName() == "VirusDebris")
			{
				if (g_EventManager->CheckCollition(*vSprite[i]->GetSpriteRect(), *vSprite[0]->GetSpriteMask()))
				{
					delete vSprite[i];
					Virus_Debris_Count--;
					Virus_Debris_Eaten++;
					vSprite[i] = nullptr;
				}
			}
		}
	}

	vSprite[0]->Update();
	sprintf(Virus_Debris_Text[0], "바이러스 잔해 수 : %d", Virus_Debris_Count);
	sprintf(Virus_Debris_Text[1], "먹은 바이러스 수 : %d", Virus_Debris_Eaten);
	g_TextManager->ModifyText(Virus_Debris_Text[0], Virus_Debris_Text_idx[0]);
	g_TextManager->ModifyText(Virus_Debris_Text[1], Virus_Debris_Text_idx[1]);
}


void CScene_Game::Release()
{
	g_TextManager->DestroyTextAll();
}

