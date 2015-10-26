// Virus_Main.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Director.h"


#undef main

int main(int argc, char* argv[])
{
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