#include "Paletka.h"
#include <glut.h>
#include "Plansza.h"

Racket::Racket(int player, float width, float positionX, float positionY, float colorR, float colorG, float colorB, Board *board, Ball *ball) : Object(colorR, colorG, colorB)
{
	this -> width = width;
	this -> positionX = positionX;
	this -> positionY = positionY;
	this -> board = board;
	this -> ball = ball;
	this -> player = player;
}

void Racket::paint()
{
	glColor3f(colorR, colorG, colorB);
	glBegin(GL_QUADS);
		glVertex3f(positionX - width/2, positionY, 0.0);
		glVertex3f(positionX + width/2, positionY, 0.0);
		glVertex3f(positionX + width/2, positionY-1, 0.0);
		glVertex3f(positionX - width/2, positionY-1, 0.0);
	glEnd();
}

void Racket::moveLeft()
{
	if( positionX - width/2 - 1 > -board -> getWidth()/2 )
	this -> positionX = positionX - 1;
}

void Racket::moveRight()
{
	if ( positionX + width/2 + 1 < board -> getWidth()/2 )
	this->positionX = positionX + 1;
}

std::string Racket::getWidth()
{
	if (width == 3)
		return "small";

	if (width == 7)
		return "normal";

	if (width == 10)
		return "big";

	return "unknow";
}

void Racket::nextWidth()
{
	if (width == 3)
	{
		width = 7;
		return;
	}

	if (width == 7)
	{
		width = 10;
		return;
	}

	if (width == 10)
	{
		width = 3;
		return;
	}

	width = 7;
}

void Racket::start()
{
	if (isHoldingBall())
		ball -> setMoving();
}

bool Racket::isHoldingBall()
{
	if (ball -> getPositionX() - ball -> getSize() > positionX + width / 2)
		return false;
	if (ball -> getPositionX() + ball -> getSize() < positionX - width / 2)
		return false;

	if (player == 1)
		if (ball -> getPositionY() - ball -> getSize() <= positionY) //for racket 1
			return true;
	if (player == 2)
		if (ball -> getPositionY() + ball -> getSize() >= positionY-1) //for racket 2
			return true;
	return false;
}

float Racket::getPositionX()
{
	return positionX;
}

Racket::~Racket(){}
