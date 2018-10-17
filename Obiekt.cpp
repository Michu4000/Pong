#include "Obiekt.h"



Obiekt::Obiekt(float kolor_r, float kolor_g, float kolor_b)
{
	this->kolor_r = kolor_r;
	this->kolor_g = kolor_g;
	this->kolor_b = kolor_b;
}

std::string Obiekt::getKolor()
{
	if ((kolor_r < 1 && kolor_r > 0) || (kolor_g < 1 && kolor_g > 0) || (kolor_b < 1 && kolor_b > 0))
		return "nieznany";

	if (kolor_r == 1)
	{
		if (kolor_g == 1)
		{
			if (kolor_b == 1)
				return "bialy";
			else return "zolty";
		}
		else
		{
			if (kolor_b == 1)
				return "fioletowy";
			else return "czerwony";
		}
	}
	else
		if (kolor_g == 1)
		{
			if (kolor_b == 1)
				return "blekitny";
			else return "zielony";
		}
		else
			if (kolor_b == 1)
				return "niebieski";
			else return "czarny";
}

void Obiekt::nastKolor()
{
	//nieznany, czarny, czerwony, zielony, niebieski, bialy, fioletowy, blekitny, zolty
	if (getKolor() == "nieznany")
	{
		kolor_r = 0;
		kolor_g = 0;
		kolor_b = 0;
		return;
	}

	if (getKolor() == "czarny")
	{
		kolor_r = 1;
		kolor_g = 0;
		kolor_b = 0;
		return;
	}
	if (getKolor() == "czerwony")
	{
		kolor_r = 0;
		kolor_g = 1;
		kolor_b = 0;
		return;
	}
	if (getKolor() == "zielony")
	{
		kolor_r = 0;
		kolor_g = 0;
		kolor_b = 1;
		return;
	}
	if (getKolor() == "niebieski")
	{
		kolor_r = 1;
		kolor_g = 1;
		kolor_b = 1;
		return;
	}
	if (getKolor() == "bialy")
	{
		kolor_r = 1;
		kolor_g = 0;
		kolor_b = 1;
		return;
	}
	if (getKolor() == "fioletowy")
	{
		kolor_r = 0;
		kolor_g = 1;
		kolor_b = 1;
		return;
	}
	if (getKolor() == "blekitny")
	{
		kolor_r = 1;
		kolor_g = 1;
		kolor_b = 0;
		return;
	}
	if (getKolor() == "zolty")
	{
		kolor_r = 0;
		kolor_g = 0;
		kolor_b = 0;
		return;
	}
}

Obiekt::~Obiekt()
{
}
