#include "Clouds.h"

Clouds::Clouds(LPCTSTR bitmapPath, Graphics* graphics, float x, float y, float xSpeed)
	: Animation(bitmapPath, graphics)
{
	this->x = x;
	this->y = y;
	this->xSpeed = xSpeed;
}

void Clouds::Update()
{
	MoveRight();
}

void Clouds::MoveRight()
{
	x += xSpeed;

	if (x >= SCREEN_WIDTH)
	{
		x = SCREEN_WIDTH / SCREEN_WIDTH - 1;
	}
}

void Clouds::Render()
{
	sprites->Draw((1 / 10) % 1, x, y);
}