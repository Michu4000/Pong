#include "Pilka.h"
#include <glut.h>
#include "Plansza.h"

#define PI 3.141593

Pilka::Pilka(float wielkosc, float szybkosc, float kolor_r, float kolor_g, float kolor_b, float polozenie_x, float polozenie_y, Plansza *plansza) : Obiekt(kolor_r, kolor_g, kolor_b)
{
	this->wielkosc = wielkosc;
	this->szybkosc = szybkosc;
	this->polozenie_x = polozenie_x;
	this->polozenie_y = polozenie_y;
	this->plansza = plansza;
	this->wruchu = false;
}

void Pilka::Rysuj()
{
	glColor3f(kolor_r, kolor_g, kolor_b);
	glPushMatrix();
	glTranslatef(polozenie_x, polozenie_y, 0);
	glutSolidSphere(wielkosc, 10, 10);
	glPopMatrix();
}

std::string Pilka::getWielkosc()
{
	if (wielkosc == 0.25)
		return "mala";

	if (wielkosc == 0.5)
		return "normalna";

	if (wielkosc == 1)
		return "duza";

	return "nieznana";
}

void Pilka::nastWielkosc()
{
	if (wielkosc == 0.25)
	{
		wielkosc = 0.5;
		return;
	}

	if (wielkosc == 0.5)
	{
		wielkosc = 1;
		return;
	}

	if (wielkosc == 1)
	{
		wielkosc = 0.25;
		return;
	}

	wielkosc = 0.5;
}

float Pilka::getPolozenie_x()
{
	return polozenie_x;
}

float Pilka::getPolozenie_y()
{
	return polozenie_y;
}

float Pilka::getRozmiar()
{
	return wielkosc;
}

void Pilka::ustawPilke(int gracz)
{
	wruchu = false;
	polozenie_x = 0;

	if (gracz == 1)
	{
		polozenie_y = -14 + wielkosc;
		zmienKat(0);
	}

	if (gracz == 2)
	{
		polozenie_y = 14 - wielkosc;
		zmienKat(PI/2);
	}
}

void Pilka::ustawPilke(float x, float y)
{
	polozenie_x = x;
	polozenie_y = y;
}

void Pilka::Ruch(int gracz)
{
	wruchu = true;
}

float Pilka::getSzybkosc()
{
	return szybkosc;
}

float Pilka::getKat()
{
	return kat;
}

void Pilka::zmienSzybkosc(float szybkosc)
{
	this->szybkosc = szybkosc;
}

void Pilka::zmienKat(float kat)
{
	this->kat = kat;
}

bool Pilka::getWruchu()
{
	return wruchu;
}

void Pilka::nastPredkosc()
{
	if(szybkosc == 4)
	{
		szybkosc = 8;
		return;
	}
	
	if (szybkosc == 8)
	{
		szybkosc = 20;
		return;
	}
	if (szybkosc == 20)
	{
		szybkosc = 4;
		return;
	}

	szybkosc = 4;
}

std::string Pilka::getPredkosc()
{
	if (szybkosc == 4)
		return "wolna";
	if (szybkosc == 8)
		return "normalna";
	if (szybkosc == 20)
		return "szybka";
	return "nieznana";
}

Pilka::~Pilka()
{
}
