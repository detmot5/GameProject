#include "Clouds.h"

Clouds::Clouds(LPCTSTR bitmapPath, Graphics* graphics, float x, float y, float xSpeed)
	: Animation(bitmapPath, graphics, new GamePoint(x, y), new GameVector(xSpeed, 0), new GameVector(0, 0), false)
{

}



void Clouds::Update(double timeDelta)
{
	Animation::Update(timeDelta);
	MoveRight();
}