#include "Paletka.h"
#include <glut.h>
#include "Plansza.h"

Paletka::Paletka(int gracz, float szerokosc, float polozenie_x, float polozenie_y, float kolor_r, float kolor_g, float kolor_b, Plansza *plansza, Pilka *pilka) : Obiekt(kolor_r, kolor_g, kolor_b)
{
	this->szerokosc = szerokosc;
	this->polozenie_x = polozenie_x;
	this->polozenie_y = polozenie_y;
	this->plansza = plansza;
	this->pilka = pilka;
	this->gracz = gracz;
}


void Paletka::Rysuj()
{
	glColor3f(kolor_r, kolor_g, kolor_b);
	glBegin(GL_QUADS);
		glVertex3f(polozenie_x-szerokosc/2, polozenie_y, 0.0);
		glVertex3f(polozenie_x+szerokosc/2, polozenie_y, 0.0);
		glVertex3f(polozenie_x+szerokosc/2, polozenie_y-1, 0.0);
		glVertex3f(polozenie_x -szerokosc/2, polozenie_y-1, 0.0);
	glEnd();
}

void Paletka::Ruch_L()
{
	if( polozenie_x-szerokosc/2-1 > -plansza->getSzerokosc()/2 )
	this->polozenie_x = polozenie_x - 1;
}

void Paletka::Ruch_P()
{
	if ( polozenie_x+szerokosc/2+1 < plansza->getSzerokosc()/2 )
	this->polozenie_x = polozenie_x + 1;
}

std::string Paletka::getSzerokosc()
{
	if (szerokosc == 3)
		return "mala";

	if (szerokosc == 7)
		return "normalna";

	if (szerokosc == 10)
		return "duza";

	return "nieznana";
}

void Paletka::nastSzerokosc()
{
	if (szerokosc == 3)
	{
		szerokosc = 7;
		return;
	}

	if (szerokosc == 7)
	{
		szerokosc = 10;
		return;
	}

	if (szerokosc == 10)
	{
		szerokosc = 3;
		return;
	}

	szerokosc = 7;
}

void Paletka::Start()
{
	if ( PosiadaniePilki() )
		pilka->Ruch(gracz);
}

bool Paletka::PosiadaniePilki()
{
	if (pilka->getPolozenie_x() - pilka->getRozmiar() > polozenie_x + szerokosc / 2)
		return false;
	if (pilka->getPolozenie_x() + pilka->getRozmiar() < polozenie_x - szerokosc / 2)
		return false;

	if (gracz==1)
		if (pilka->getPolozenie_y() - pilka->getRozmiar() <= polozenie_y)//dla paletki1
			return true;
	if(gracz==2)
		if (pilka->getPolozenie_y() + pilka->getRozmiar() >= polozenie_y-1)//dla paletki2
			return true;
	return false;
}

float Paletka::getPolozenie_x()
{
	return polozenie_x;
}

Paletka::~Paletka()
{
}
