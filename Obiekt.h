#pragma once
#include <string>

class Obiekt
{
protected:
	float kolor_r;
	float kolor_g;
	float kolor_b;
public:
	Obiekt(float kolor_r, float kolor_g, float kolor_b);
	std::string getKolor();
	void nastKolor();
	~Obiekt();
};

