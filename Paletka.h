#pragma once
#include "Plansza.h"
#include "Obiekt.h"
#include "Pilka.h"
#include <string>

class Paletka : public Obiekt
{
private:
	int gracz;
	float szerokosc;
	float polozenie_x;
	float polozenie_y;
	Plansza *plansza;
	Pilka *pilka;
public:
	Paletka(int gracz, float szerokosc, float polozenie_x, float polozenie_y, float kolor_r, float kolor_g, float kolor_b, Plansza *plansza, Pilka *pilka);
	void Rysuj();
	void Ruch_L();
	void Ruch_P();
	void Start();
	bool PosiadaniePilki();
	std::string getSzerokosc();
	void nastSzerokosc();
	float getPolozenie_x();
	~Paletka();
};

