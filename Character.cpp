#include "GameController.h"
#include "Character.h"
#include "World.h"

short RaiseIndicator;
short DescentIndicator;

Character::Character(LPCTSTR bitmapPath, Graphics* graphics, float x, float y, float xSpeed, float ySpeed, float height, float gravity)
	: Animation(bitmapPath, graphics, false)
{
	this->x = x;
	this->y = y;
	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
	this->height = height;
	this->gravity = gravity;
}

void Character::Update()
{
	if (GetKeyState(Right) & 0x8000)
	{
		MoveRight();
	}

	if (GetKeyState(Left) & 0x8000)
	{
		MoveLeft();
	}

	if (GetKeyState(Up) & 0x8000 || y < 300)
	{
		MoveUp();
	}
}


