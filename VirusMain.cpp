// Virus_Main.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Director.h"


#include <crtdbg.h>
#ifdef _DEBUG

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )   // #include <new.h>������ operator new�� malloc�� 
#define _CRTDBG_MAP_ALLOC
// Derived�ؼ� ���� �� ���, ��� �� �� ����.

#endif


#undef main

int main(int argc, char* argv[])
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//_CrtSetBreakAlloc(156);//�̱���

	//_CrtSetBreakAlloc(155);//�̱���

	//_CrtSetBreakAlloc(154);//�̱���

	//_CrtSetBreakAlloc(153);//CScene �����Ҵ�

	//_CrtSetBreakAlloc(152);//Scene_MainMenu �����Ҵ�

	//_CrtSetBreakAlloc(151);//�̱���

	//_CrtSetBreakAlloc(147);//�˼����� (�Ƹ� �̱���)

	//_CrtSetBreakAlloc(146);//�̱���

	//_CrtSetBreakAlloc(145);//�̱���

	g_Director->Init();

	g_Director->GameLoop();

	g_Director->Release();

	return 0;
}

//����Ʈ Ŭ��				1
//�����̾���� ���ͺ�		3
//�� ���� ���			4
//������Ʈ ����
//�� �ø���..
//�޸���
//�Ƹ޸�ĭ ������			2//
//�� ���̵�ƼƼ