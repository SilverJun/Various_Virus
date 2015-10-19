// Virus_Main.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Director.h"


#include <crtdbg.h>
#ifdef _DEBUG

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )   // #include <new.h>등으로 operator new나 malloc을 
#define _CRTDBG_MAP_ALLOC
// Derived해서 정의 한 경우, 사용 할 수 없다.

#endif


#undef main

int main(int argc, char* argv[])
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//_CrtSetBreakAlloc(156);//싱글턴

	//_CrtSetBreakAlloc(155);//싱글턴

	//_CrtSetBreakAlloc(154);//싱글턴

	//_CrtSetBreakAlloc(153);//CScene 동적할당

	//_CrtSetBreakAlloc(152);//Scene_MainMenu 동적할당

	//_CrtSetBreakAlloc(151);//싱글턴

	//_CrtSetBreakAlloc(147);//알수없음 (아마 싱글턴)

	//_CrtSetBreakAlloc(146);//싱글턴

	//_CrtSetBreakAlloc(145);//싱글턴

	g_Director->Init();

	g_Director->GameLoop();

	g_Director->Release();

	return 0;
}

//파이트 클럽				1
//벰파이어와의 인터뷰		3
//조 블랙의 사랑			4
//포레스트 검프
//본 시리즈..
//메멘토
//아메리칸 사이코			2//
//본 아이덴티티