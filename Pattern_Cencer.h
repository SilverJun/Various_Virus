#pragma once
#include "Pattern_Strategy.h"

//create a circle and it goes bigger.
//this pattern is in center.
class CPattern_Cencer :
	public CPattern_Strategy
{
public:
	CPattern_Cencer();
	~CPattern_Cencer();

	virtual void Behavior() override;
};
