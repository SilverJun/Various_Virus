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
	std::cout << "플레이어 동적할당" << std::endl;
	VirusCreateTime = 800;
	VirusCode = RED;
	Virus_Debris_Count = 0;
	Virus_Debris_Eaten = 0;
	Vaccine_Usable = 5;
	Pattern = new VirusPattern();
	std::cout << "바이러스패턴관리자 동적할당" << std::endl;
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
		std::cout << "바이러스잔해 동적할당" << std::endl;
		Virus_Debris_Count++;
	}
	else
	{
		addSprite(new CSprite_Virus(code));
		std::cout << "바이러스 동적할당" << std::endl;
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
	// 키입력 처리
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
							std::cout << "바이러스잔해 동적할당" << std::endl;
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
							std::cout << "바이러스잔해 동적할당" << std::endl;
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
							std::cout << "바이러스잔해 동적할당" << std::endl;
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
							std::cout << "바이러스잔해 동적할당" << std::endl;
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
			else
			{
				SDL_Rect tmp = *vSprite[0]->GetSpriteRect();
				
				if (vSprite[0]->GetSpriteDirection() == cLEFT)
				{
					tmp.x += 5;
					if (g_EventManager->CheckCollition(*vSprite[i]->GetSpriteRect(), tmp))
					{
						static_cast<CSprite_Player *>(vSprite[0])->SetPlayerbIsMove(false);
					}
					else
					{
						if (!(*static_cast<CSprite_Player *>(vSprite[0])->GetPlayerbIsMove()))
						{
							static_cast<CSprite_Player *>(vSprite[0])->SetPlayerbIsMove(true);
						}
						
					}
				}
				if (vSprite[0]->GetSpriteDirection() == cRIGHT)
				{
					tmp.x -= 5;
					if (g_EventManager->CheckCollition(*vSprite[i]->GetSpriteRect(), tmp))
					{
						static_cast<CSprite_Player *>(vSprite[0])->SetPlayerbIsMove(false);
					}
					else
					{
						if (!(*static_cast<CSprite_Player *>(vSprite[0])->GetPlayerbIsMove()))
						{
							static_cast<CSprite_Player *>(vSprite[0])->SetPlayerbIsMove(true);
						}

					}
				}
				if (vSprite[0]->GetSpriteDirection() == cUP)
				{
					tmp.y += 5;
					if (g_EventManager->CheckCollition(*vSprite[i]->GetSpriteRect(), tmp))
					{
						static_cast<CSprite_Player *>(vSprite[0])->SetPlayerbIsMove(false);
					}
					else
					{
						if (!(*static_cast<CSprite_Player *>(vSprite[0])->GetPlayerbIsMove()))
						{
							static_cast<CSprite_Player *>(vSprite[0])->SetPlayerbIsMove(true);
						}

					}
				}
				if (vSprite[0]->GetSpriteDirection() == cDOWN)
				{
					tmp.y -= 5;
					if (g_EventManager->CheckCollition(*vSprite[i]->GetSpriteRect(), tmp))
					{
						static_cast<CSprite_Player *>(vSprite[0])->SetPlayerbIsMove(false);
					}
					else
					{
						if (!(*static_cast<CSprite_Player *>(vSprite[0])->GetPlayerbIsMove()))
						{
							static_cast<CSprite_Player *>(vSprite[0])->SetPlayerbIsMove(true);
						}

					}
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
	delete Pattern;
}

