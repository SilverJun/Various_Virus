// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>

//======== �߰� ���̺귯�� ��� ========
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//#include <fmod.hpp>

enum
{
	Up,
	Down,
	Left,
	Right,
	Space,
	esc,
	n1,
	n2,
	n3,
	n4,
};

#define WINDOW_DEFAULT_W	1280
#define WINDOW_DEFAULT_H	800

using namespace std;


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
