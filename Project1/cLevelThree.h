#pragma once
#include "cLevel.h"

class cLevelThree : public cLevel {
	cLevelThree();
	virtual ~cLevelThree();

	virtual bool playCondition();
};