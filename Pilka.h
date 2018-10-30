#pragma once
#include "Plansza.h"
#include "Obiekt.h"
#include <string>

class Ball : public Object
{
private:
	float size;
	float positionX;
	float positionY;
	float speed;
	bool isMoving;
	float angle;
public:
	Ball(float size, float speed, float clorR, float clorG, float clorB, float positionX, float positionY);
	void paint();
	void setMoving();
	std::string getSizeName();
	void nextSize();
	float getPositionX();
	float getPositionY();
	float getSpeed();
	void setSpeed(float speed);
	float getAngle();
	void setAngle(float angle);
	float getSize();
	void placeBall(int player);
	void placeBall(float x, float y);
	bool getMoving();
	void nextSpeed();
	std::string getSpeedName();
	~Ball();
};
