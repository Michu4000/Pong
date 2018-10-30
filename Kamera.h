#pragma once
#define distMin -10
#define distMax -150

class Camera
{
private:
	float x;
	float y;
	float z;
	float zoom;
public:
	Camera(float x, float y, float z, float zoom);
	float getX();
	float getY();
	float getZ();
	float getZoom();
	void xPlus();
	void xMinus();
	void yPlus();
	void yMinus();
	void zPlus();
	void zMinus();
	void zoomPlus();
	void zoomMinus();
	~Camera();
};
