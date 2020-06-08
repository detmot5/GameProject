#include "Clouds.h"

Clouds::Clouds(LPCTSTR bitmapPath, Graphics* graphics, float x, float y, float xSpeed)
	: Animation(bitmapPath, graphics, new GameVector(x, y), new GameVector(xSpeed, 0), new GameVector(0, 0), false){

}


void Clouds::Update()
{
	Animation::Update();
	MoveRight();
}