#include "Camera.h"

Camera::Camera(float x, float y, float z, float zoom)
{
	this -> x = x;
	this -> y = y;
	this -> z = z;
	this -> zoom = zoom;
}

float Camera::getX()
{
	return x;
}

float Camera::getY()
{
	return y;
}

float Camera::getZ()
{
	return z;
}

float Camera::getZoom()
{
	return zoom;
}

void Camera::xPlus()
{
	x += 1.0;
}

void Camera::xMinus()
{
	x -= 1.0;
}

void Camera::yPlus()
{
	y += 1.0;
}

void Camera::yMinus()
{
	y -= 1.0;
}

void Camera::zPlus()
{
	z += 1.0;
}

void Camera::zMinus()
{
	z -= 1.0;
}

void Camera::zoomPlus()
{
	if(zoom < distMin)
		zoom += 0.5;
}

void Camera::zoomMinus()
{
	if(zoom > distMax)
		zoom -= 0.5;
}

Camera::~Camera(){}
