#include "Clouds.h"

Clouds::Clouds(LPCTSTR bitmapPath, Graphics* graphics, float x, float y, float xSpeed)
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