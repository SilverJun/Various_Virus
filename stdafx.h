// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>

//======== 추가 라이브러리 헤더 ========
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


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
