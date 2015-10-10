#pragma once

#include "Singleton.h"
#include "Pattern_Strategy.h"

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

