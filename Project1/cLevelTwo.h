#pragma once
#include "cLevel.h"

class cLevelTwo : public cLevel {
	cLevelTwo();
	virtual ~cLevelTwo();

	virtual bool playCondition();
};