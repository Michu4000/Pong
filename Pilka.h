#pragma once
#include "Plansza.h"
#include "Obiekt.h"
#include <string>

class Pilka : public Obiekt
{
private:
	float wielkosc;
	float polozenie_x;
	float polozenie_y;
	float szybkosc;
	bool wruchu;
	float kat;
	Plansza *plansza;
public:
	Pilka(float wielkosc, float szybkosc, float kolor_r, float kolor_g, float kolor_b, float polozenie_x, float polozenie_y, Plansza *plansza);
	void Rysuj();
	void Ruch(int gracz);
	std::string getWielkosc();
	void nastWielkosc();
	float getPolozenie_x();
	float getPolozenie_y();
	float getSzybkosc();
	void zmienSzybkosc(float szybkosc);
	float getKat();
	void zmienKat(float kat);
	float getRozmiar();
	void ustawPilke(int gracz);
	void ustawPilke(float x, float y);
	bool getWruchu();
	void nastPredkosc();
	std::string getPredkosc();
	~Pilka();
};

