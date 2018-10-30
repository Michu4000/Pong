#include "Object.h"

Object::Object(float colorR, float colorG, float colorB)
{
	this -> colorR = colorR;
	this -> colorG = colorG;
	this -> colorB = colorB;
}

std::string Object::getColor()
{
	if ((colorR < 1 && colorR > 0) || (colorG < 1 && colorG > 0) || (colorB < 1 && colorB > 0))
		return "unknow";

	if (colorR == 1)
	{
		if (colorG == 1)
		{
			if (colorB == 1)
				return "white";
			else return "yellow";
		}
		else
		{
			if (colorB == 1)
				return "violet";
			else return "red";
		}
	}
	else
		if (colorG == 1)
		{
			if (colorB == 1)
				return "azure";
			else return "green";
		}
		else
			if (colorB == 1)
				return "blue";
			else return "black";
}

void Object::nextColor()
{
	//unknow, black, red, green, blue, white, violet, azure, yellow
	if (getColor() == "unknow")
	{
		colorR = 0;
		colorG = 0;
		colorB = 0;
		return;
	}

	if (getColor() == "black")
	{
		colorR = 1;
		colorG = 0;
		colorB = 0;
		return;
	}
	if (getColor() == "red")
	{
		colorR = 0;
		colorG = 1;
		colorB = 0;
		return;
	}
	if (getColor() == "green")
	{
		colorR = 0;
		colorG = 0;
		colorB = 1;
		return;
	}
	if (getColor() == "blue")
	{
		colorR = 1;
		colorG = 1;
		colorB = 1;
		return;
	}
	if (getColor() == "white")
	{
		colorR = 1;
		colorG = 0;
		colorB = 1;
		return;
	}
	if (getColor() == "violet")
	{
		colorR = 0;
		colorG = 1;
		colorB = 1;
		return;
	}
	if (getColor() == "azure")
	{
		colorR = 1;
		colorG = 1;
		colorB = 0;
		return;
	}
	if (getColor() == "yellow")
	{
		colorR = 0;
		colorG = 0;
		colorB = 0;
		return;
	}
}

Object::~Object(){}
