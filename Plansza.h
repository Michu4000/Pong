#pragma once
#include "Obiekt.h"
#include <string>

class Plansza : public Obiekt
{
private:
	float szerokosc;
	float wysokosc;
	float KolorTla_R;
	float KolorTla_G;
	float KolorTla_B;
public:
	Plansza(float szerokosc, float wysokosc, float kolor_r, float kolor_g, float kolor_b, float KolorTla_R, float KolorTla_G, float KolorTla_B);
	float getSzerokosc();
	float getWysokosc();
	float getKolorTla_R();
	float getKolorTla_G();
	float getKolorTla_B();
	std::string getKolorTla();
	void nastKolorTla();
	void Rysuj();
	~Plansza();
};

