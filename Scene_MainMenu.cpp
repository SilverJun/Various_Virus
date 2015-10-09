#include "stdafx.h"
#include "Scene_MainMenu.h"
#include "Director.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "TextManager.h"


CScene_MainMenu::CScene_MainMenu() : CScene(1)
{
	MenuBox[Start]	= { 200, 300, 0, 50 };
	MenuBox[Rule]	= { 200, 400, 0, 50 };
	MenuBox[Score] = { 200, 500, 0, 50 };
	MenuBox[Credit] = { 200, 600, 0, 50 };
	MenuBox[Exit]	= { 200, 700, 0, 50 };

	strcpy(MenuString[Start], "게임시작");
	strcpy(MenuString[Rule],	 "게임규칙");
	strcpy(MenuString[Score], "점    수");
	strcpy(MenuString[Credit], "제 작 자");
	strcpy(MenuString[Exit], "게임종료");

	MenuBox[Start].w = (strlen(MenuString[Start])-1) * 20;
	MenuBox[Rule].w = (strlen(MenuString[Rule])-1) * 20;
	MenuBox[Score].w = (strlen(MenuString[Score])-1) * 20;
	MenuBox[Credit].w = (strlen(MenuString[Credit])-1) * 20;
	MenuBox[Exit].w = (strlen(MenuString[Exit])-1) * 20;
}


CScene_MainMenu::~CScene_MainMenu()
{
	Release();
}


void CScene_MainMenu::Init()
{
	for (int i = 0; i < 5; i++)
	{
		g_TextManager->CreateText(MenuString[i], &MenuBox[i]);
	}
}


void CScene_MainMenu::Update()
{
	if (g_EventManager->g_Event.button.button == SDL_BUTTON_LEFT)
	{
		if (g_EventManager->CheckCollition_by_mouse(MenuBox[Start]))
		{
			g_SceneManager->SetScene(sGame);
		}
		else if (g_EventManager->CheckCollition_by_mouse(MenuBox[Rule]))
		{
			g_SceneManager->SetScene(sRule);
		} 
		else if (g_EventManager->CheckCollition_by_mouse(MenuBox[Score]))
		{
			g_SceneManager->SetScene(sScore);
		}
		else if (g_EventManager->CheckCollition_by_mouse(MenuBox[Credit]))
		{
			g_SceneManager->SetScene(sCredit);
		}
		else if (g_EventManager->CheckCollition_by_mouse(MenuBox[Exit]))
		{
			g_Director->GameDone = true;
		}
	}
}


void CScene_MainMenu::Release()
{
	g_TextManager->DestroyTextAll();
}


