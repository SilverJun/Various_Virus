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

	strcpy(CreditString[0], "* ������ *");
	strcpy(CreditString[1], "��ȹ : �̿���");
	strcpy(CreditString[2], "���α׷��� : ������");
	strcpy(CreditString[3], "�׷��� : ������");
	strcpy(CreditString[4], "�÷������ּż� �����մϴ�! �ƹ�Ű�� ���� �ּ���!");

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

