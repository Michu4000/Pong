#include "Plansza.h"
#include <glut.h>


Plansza::Plansza(float szerokosc, float wysokosc, float kolor_r, float kolor_g, float kolor_b, float KolorTla_R, float KolorTla_G, float KolorTla_B) : Obiekt(kolor_r, kolor_g, kolor_b)
{
	this->szerokosc = szerokosc;
	this->wysokosc = wysokosc;
	this->KolorTla_R = KolorTla_R;
	this->KolorTla_G = KolorTla_G;
	this->KolorTla_B = KolorTla_B;
}

void Plansza::Rysuj()
{
	glColor3f(kolor_r, kolor_g, kolor_b);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-szerokosc/2, wysokosc/2, 0.0);
		glVertex3f(szerokosc/2, wysokosc/2, 0.0);
		glVertex3f(szerokosc/2, -wysokosc/2, 0.0);
		glVertex3f(-szerokosc/2, -wysokosc/2, 0.0);
	glEnd();
}

float Plansza::getSzerokosc()
{
	return szerokosc;
}

float Plansza::getWysokosc()
{
	return wysokosc;
}

float Plansza::getKolorTla_R()
{
	return KolorTla_R;
}

float Plansza::getKolorTla_G()
{
	return KolorTla_G;
}

float Plansza::getKolorTla_B()
{
	return KolorTla_B;
}

std::string Plansza::getKolorTla()
{
	if ((KolorTla_R < 1 && KolorTla_R > 0) || (KolorTla_G < 1 && KolorTla_G > 0) || (KolorTla_B < 1 && KolorTla_B > 0))
	return "nieznany";

	if (KolorTla_R == 1)
	{
		if (KolorTla_G == 1)
		{
			if (KolorTla_B == 1)
				return "bialy";
			else return "zolty";
		}
		else
		{
			if (KolorTla_B == 1)
				return "fioletowy";
			else return "czerwony";
		}
	}
	else
		if (KolorTla_G == 1)
		{
			if (KolorTla_B == 1)
				return "blekitny";
			else return "zielony";
		}
		else
			if (KolorTla_B == 1)
				return "niebieski";
			else return "czarny";
}

void Plansza::nastKolorTla()
{
	//nieznany, czarny, czerwony, zielony, niebieski, bialy, fioletowy, blekitny, zolty
	if (getKolorTla() == "nieznany")
	{
		KolorTla_R = 0;
		KolorTla_G = 0;
		KolorTla_B = 0;
		return;
	}

	if (getKolorTla() == "czarny")
	{
		KolorTla_R = 1;
		KolorTla_G = 0;
		KolorTla_B = 0;
		return;
	}
	if (getKolorTla() == "czerwony")
	{
		KolorTla_R = 0;
		KolorTla_G = 1;
		KolorTla_B = 0;
		return;
	}
	if (getKolorTla() == "zielony")
	{
		KolorTla_R = 0;
		KolorTla_G = 0;
		KolorTla_B = 1;
		return;
	}
	if (getKolorTla() == "niebieski")
	{
		KolorTla_R = 1;
		KolorTla_G = 1;
		KolorTla_B = 1;
		return;
	}
	if (getKolorTla() == "bialy")
	{
		KolorTla_R = 1;
		KolorTla_G = 0;
		KolorTla_B = 1;
		return;
	}
	if (getKolorTla() == "fioletowy")
	{
		KolorTla_R = 0;
		KolorTla_G = 1;
		KolorTla_B = 1;
		return;
	}
	if (getKolorTla() == "blekitny")
	{
		KolorTla_R = 1;
		KolorTla_G = 1;
		KolorTla_B = 0;
		return;
	}
	if (getKolorTla() == "zolty")
	{
		KolorTla_R = 0;
		KolorTla_G = 0;
		KolorTla_B = 0;
		return;
	}
}

Plansza::~Plansza()
{
}
