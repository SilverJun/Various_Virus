// Virus_Main.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

//����Ʈ Ŭ��				1
//�����̾���� ���ͺ�		3
//�� ���� ���			4
//������Ʈ ����
//�� �ø���..
//�޸���
//�Ƹ޸�ĭ ������			2//
//�� ���̵�ƼƼ