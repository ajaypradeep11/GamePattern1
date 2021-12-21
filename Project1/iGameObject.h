#pragma once
#include<string>

class iGameObject {
public:
	iGameObject() {}
	virtual ~iGameObject() {}
	virtual void Update(double deltaTime) = 0;

	virtual std::string getName(void) = 0;
};