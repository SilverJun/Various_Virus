#pragma once

#include "Singleton.h"

class VirusPattern : public Singleton<VirusPattern>
{
public:
	VirusPattern();
	~VirusPattern();
};

