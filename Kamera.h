#pragma once
#define odlmin -10
#define odlmax -150

class Kamera
{
private:
	float X;
	float Y;
	float Z;
	float zoom;
public:
	Kamera(float X, float Y, float Z, float zoom);
	float getX();
	float getY();
	float getZ();
	float getzoom();
	void Xplus();
	void Xminus();
	void Yplus();
	void Yminus();
	void Zplus();
	void Zminus();
	void zoomplus();
	void zoomminus();
	~Kamera();
};

