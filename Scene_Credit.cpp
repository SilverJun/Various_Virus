#include "stdafx.h"
#include "Scene_Credit.h"

#include "TextManager.h"


CScene_Credit::CScene_Credit() : CScene(5)
{
	CreditBox[0] = { 200, 200, 0, 50 };
	CreditBox[1] = { 200, 350, 0, 50 };
	CreditBox[2] = { 200, 400, 0, 50 };
	CreditBox[3] = { 200, 450, 0, 50 };
	CreditBox[4] = { 200, 600, 0, 50 };

	strcpy(CreditString[0], "* 제작자 *");
	strcpy(CreditString[1], "기획 : 이용희");
	strcpy(CreditString[2], "프로그래밍 : 장은준");
	strcpy(CreditString[3], "그래픽 : 박정후");
	strcpy(CreditString[4], "플레이해주셔서 감사합니다! 아무키나 눌러 주세요!");

	CreditBox[0].w = (strlen(CreditString[0]) - 1) * 20;
	CreditBox[1].w = (strlen(CreditString[1]) - 1) * 20;
	CreditBox[2].w = (strlen(CreditString[2]) - 1) * 20;
	CreditBox[3].w = (strlen(CreditString[3]) - 1) * 20;
	CreditBox[4].w = (strlen(CreditString[4]) - 1) * 20;
}


CScene_Credit::~CScene_Credit()
{
}


void CScene_Credit::Init()
{
	for (int i = 0; i < 5; i++)
	{
		g_TextManager->CreateText(CreditString[i], &CreditBox[i]);
	}
}


void CScene_Credit::Update()
{

}


void CScene_Credit::Release()
{
	g_TextManager->DestroyTextAll();
}

