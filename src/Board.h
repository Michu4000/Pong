#pragma once
#include "Object.h"
#include <string>

class Board : public Object
{
private:
	float width;
	float height;
	float backgroundColorR;
	float backgroundColorG;
	float backgroundColorB;
public:
	Board(float width, float height, float colorR, float colorG, float colorB, float backgroundColorR, float backgroundColorG, float backgroundColorB);
	float getWidth();
	float getHeight();
	float getBackgroundColorR();
	float getBackgroundColorG();
	float getBackgroundColorB();
	std::string getBackgroundColor();
	void nextBackgroundColor();
	void paint();
	~Board();
};