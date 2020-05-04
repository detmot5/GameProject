#include "GameController.h"
#include "Character.h"


Character::Character(LPCTSTR bitmapPath, Graphics* graphics, float x, float y, float xSpeed,
	float ySpeed, float jumpHeight, float gravity)
	: Animation(bitmapPath, graphics, false)
{
	this->x = x;
	this->y = World::GetActualFloorLevel(x / 32) * 30;
	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
	this->jumpHeight = jumpHeight;
	this->gravity = gravity;
}




void Character::Update()
{
	if (GetAsyncKeyState(Right) & 0x8000)
	{
		MoveRight();
	}
	else if (GetAsyncKeyState(Left) & 0x8000)
	{
		MoveLeft();
	}
	else
	{
		index = 0;
	}
	if (GetAsyncKeyState(Up) & 0x8000 || y < World::GetActualFloorLevel(x / 32) * 30)
	{
		MoveUp();
	}	
}

void Character::Render()
{
	Animation::Render();
}




void Character::MoveUp()
{
	y += jumpHeight * ySpeed;

	jumpHeight += gravity * ySpeed;

	if (y >= World::GetActualFloorLevel(x / 32) * 30)
	{
		jumpHeight = World::GetActualFloorLevel(x / 32) * 1.92;

		y = World::GetActualFloorLevel(x / 32) * 30;
	}
}

void Character::MoveRight()
{
	index = 1;

	Animation::MoveRight();
}

void Character::MoveLeft()
{
	index = 2;

	Animation::MoveLeft();
}
