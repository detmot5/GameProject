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

UINT16 FindHighestLand(UINT16 x, UINT16 y) {
	for (UINT8 i = y/32; i < 20 ; i++) {
		if (World::isCollisionEnabled(x/32, i)) return i*32;
	}
	return 10;
}


void Character::Update()
{
	lowestLand = FindHighestLand(x, y);

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
	if (GetAsyncKeyState(Up) & 0x8000 || y < lowestLand-DEFAULT_BLOCK_SIZE/2)
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

	if (y > lowestLand - DEFAULT_BLOCK_SIZE/2)
	{
        y = lowestLand - DEFAULT_BLOCK_SIZE/2;
		jumpHeight =  25;
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


