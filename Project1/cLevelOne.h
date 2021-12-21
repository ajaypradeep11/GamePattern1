#pragma once
#include "cLevel.h"

class cLevelOne : public cLevel {
	cLevelOne();
	virtual ~cLevelOne();

	virtual bool playCondition();
};