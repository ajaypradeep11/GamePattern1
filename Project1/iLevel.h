#pragma once
#include<string>

class iLevel {
public:
	iLevel() {}
	virtual ~iLevel() {}

	virtual bool playCondition() = 0;

};