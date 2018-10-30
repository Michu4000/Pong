#include "Board.h"
#include <glut.h>

Board::Board(float width, float height, float colorR, float colorG, float colorB, float backgroundColorR, float backgroundColorG, float backgroundColorB) : Object(colorR, colorG, colorB)
{
	this -> width = width;
	this -> height = height;
	this -> backgroundColorR = backgroundColorR;
	this -> backgroundColorG = backgroundColorG;
	this -> backgroundColorB = backgroundColorB;
}

void Board::paint()
{
	glColor3f(colorR, colorG, colorB);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-width/2, height/2, 0.0);
		glVertex3f(width/2, height/2, 0.0);
		glVertex3f(width/2, -height/2, 0.0);
		glVertex3f(-width/2, -height/2, 0.0);
	glEnd();
}

float Board::getWidth()
{
	return width;
}

float Board::getHeight()
{
	return height;
}

float Board::getBackgroundColorR()
{
	return backgroundColorR;
}

float Board::getBackgroundColorG()
{
	return backgroundColorG;
}

float Board::getBackgroundColorB()
{
	return backgroundColorB;
}

std::string Board::getBackgroundColor()
{
	if ((backgroundColorR < 1 && backgroundColorR > 0) || (backgroundColorG < 1 && backgroundColorG > 0) || (backgroundColorB < 1 && backgroundColorB > 0))
	return "unknow";

	if (backgroundColorR == 1)
	{
		if (backgroundColorG == 1)
		{
			if (backgroundColorB == 1)
				return "white";
			else return "yellow";
		}
		else
		{
			if (backgroundColorB == 1)
				return "violet";
			else return "red";
		}
	}
	else
		if (backgroundColorG == 1)
		{
			if (backgroundColorB == 1)
				return "azure";
			else return "green";
		}
		else
			if (backgroundColorB == 1)
				return "blue";
			else return "black";
}

void Board::nextBackgroundColor()
{
	//unknow, black, red, green, blue, white, violet, azure, yellow
	if (getBackgroundColor() == "unknow")
	{
		backgroundColorR = 0;
		backgroundColorG = 0;
		backgroundColorB = 0;
		return;
	}

	if (getBackgroundColor() == "black")
	{
		backgroundColorR = 1;
		backgroundColorG = 0;
		backgroundColorB = 0;
		return;
	}
	if (getBackgroundColor() == "red")
	{
		backgroundColorR = 0;
		backgroundColorG = 1;
		backgroundColorB = 0;
		return;
	}
	if (getBackgroundColor() == "green")
	{
		backgroundColorR = 0;
		backgroundColorG = 0;
		backgroundColorB = 1;
		return;
	}
	if (getBackgroundColor() == "blue")
	{
		backgroundColorR = 1;
		backgroundColorG = 1;
		backgroundColorB = 1;
		return;
	}
	if (getBackgroundColor() == "white")
	{
		backgroundColorR = 1;
		backgroundColorG = 0;
		backgroundColorB = 1;
		return;
	}
	if (getBackgroundColor() == "violet")
	{
		backgroundColorR = 0;
		backgroundColorG = 1;
		backgroundColorB = 1;
		return;
	}
	if (getBackgroundColor() == "azure")
	{
		backgroundColorR = 1;
		backgroundColorG = 1;
		backgroundColorB = 0;
		return;
	}
	if (getBackgroundColor() == "yellow")
	{
		backgroundColorR = 0;
		backgroundColorG = 0;
		backgroundColorB = 0;
		return;
	}
}

Board::~Board(){}
