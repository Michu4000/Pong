#pragma once
#include "Plansza.h"
#include "Obiekt.h"
#include "Pilka.h"
#include <string>

class Racket : public Object
{
private:
	int player;
	float width;
	float positionX;
	float positionY;
	Board *board;
	Ball *ball;
public:
	Racket(int player, float width, float positionX, float positionY, float colorR, float colorG, float colorB, Board *board, Ball *ball);
	void paint();
	void moveLeft();
	void moveRight();
	void start();
	bool isHoldingBall();
	std::string getWidth();
	void nextWidth();
	float getPositionX();
	~Racket();
};