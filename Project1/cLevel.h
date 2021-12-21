#pragma once
#include "iLevel.h"
#include "globalThings.h"

class cLevel : public iLevel {
	cLevel();
	virtual ~cLevel();
	
	virtual bool playCondition();
};