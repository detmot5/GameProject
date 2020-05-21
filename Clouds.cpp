#include "Clouds.h"

Clouds::Clouds(LPCTSTR bitmapPath, Graphics* graphics, int x, int y, float xSpeed)
	: Animation(bitmapPath, graphics,false)
{
	this->x = x;
	this->y = y;
	this->xSpeed = xSpeed;
}




void Clouds::Update()
{
	MoveRight();
}