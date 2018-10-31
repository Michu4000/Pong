#pragma once
#include <string>

class Object
{
protected:
	float colorR;
	float colorG;
	float colorB;
public:
	Object(float colorR, float colorG, float colorB);
	std::string getColor();
	void nextColor();
	~Object();
};