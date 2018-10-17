#include "Kamera.h"



Kamera::Kamera(float X, float Y, float Z, float zoom)
{
	this->X = X;
	this->Y = Y;
	this->Z = Z;
	this->zoom = zoom;
}

float Kamera::getX()
{
	return X;
}

float Kamera::getY()
{
	return Y;
}

float Kamera::getZ()
{
	return Z;
}

float Kamera::getzoom()
{
	return zoom;
}

void Kamera::Xplus()
{
	X = X + 1.0;
}

void Kamera::Xminus()
{
	X = X - 1.0;
}

void Kamera::Yplus()
{
	Y = Y + 1.0;
}

void Kamera::Yminus()
{
	Y = Y - 1.0;
}

void Kamera::Zplus()
{
	Z = Z + 1.0;
}

void Kamera::Zminus()
{
	Z = Z - 1.0;
}

void Kamera::zoomplus()
{
	if(zoom < odlmin)
		zoom = zoom + 0.5;
}

void Kamera::zoomminus()
{
	if(zoom > odlmax)
		zoom = zoom - 0.5;
}

Kamera::~Kamera()
{
}
