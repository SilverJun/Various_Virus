#pragma once

#include "Singleton.h"

class VirusPattern : public Singleton<VirusPattern>
{
public:
	VirusPattern();
	~VirusPattern();

	
private:
	clock_t PatternTime;
	int PatternCode;
	bool IsDoingPattern;

	CPattern_Strategy *Pattern;
};

