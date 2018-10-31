#include "Ball.h"
#include <glut.h>
#include "Board.h"

#define PI 3.141593

Ball::Ball(float size, float speed, float colorR, float colorG, float colorB, float positionX, float positionY) : Object(colorR, colorG, colorB)
{
	this -> size = size;
	this -> speed = speed;
	this -> positionX = positionX;
	this -> positionY = positionY;
	this -> isMoving = false;
}

void Ball::paint()
{
	glColor3f(colorR, colorG, colorB);
	glPushMatrix();
	glTranslatef(positionX, positionY, 0);
	glutSolidSphere(size, 10, 10);
	glPopMatrix();
}

std::string Ball::getSizeName()
{
	if (size == 0.25)
		return "small";

	if (size == 0.5)
		return "normal";

	if (size == 1)
		return "big";

	return "unknow";
}

void Ball::nextSize()
{
	if (size == 0.25)
	{
		size = 0.5;
		return;
	}

	if (size == 0.5)
	{
		size = 1;
		return;
	}

	if (size == 1)
	{
		size = 0.25;
		return;
	}

	size = 0.5;
}

float Ball::getPositionX()
{
	return positionX;
}

float Ball::getPositionY()
{
	return positionY;
}

float Ball::getSize()
{
	return size;
}

void Ball::placeBall(int player)
{
	isMoving = false;
	positionX = 0;

	if (player == 1)
	{
		positionY = -14 + size;
		setAngle(0);
	}

	if (player == 2)
	{
		positionY = 14 - size;
		setAngle(PI/2);
	}
}

void Ball::placeBall(float x, float y)
{
	positionX = x;
	positionY = y;
}

void Ball::setMoving()
{
	isMoving = true;
}

float Ball::getSpeed()
{
	return speed;
}

float Ball::getAngle()
{
	return angle;
}

void Ball::setSpeed(float speed)
{
	this -> speed = speed;
}

void Ball::setAngle(float angle)
{
	this -> angle = angle;
}

bool Ball::getMoving()
{
	return isMoving;
}

void Ball::nextSpeed()
{
	if(speed == 4)
	{
		speed = 8;
		return;
	}
	
	if (speed == 8)
	{
		speed = 20;
		return;
	}
	if (speed == 20)
	{
		speed = 4;
		return;
	}

	speed = 4;
}

std::string Ball::getSpeedName()
{
	if (speed == 4)
		return "slow";
	if (speed == 8)
		return "normal";
	if (speed == 20)
		return "fast";
	return "unknow";
}

Ball::~Ball(){}
