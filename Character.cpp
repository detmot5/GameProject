#include "GameController.h"
#include "Character.h"


Character::Character(LPCTSTR bitmapPath, Graphics* graphics, float x, float y, float xSpeed,
	float ySpeed, float jumpHeight, float gravity)
	: Animation(bitmapPath, graphics, false)
{
	this->x = x;
	this->y = static_cast<float>( World::GetActualFloorLevel(static_cast<UINT16>(x) / 32) * 30);
	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
	this->jumpHeight = jumpHeight;
	this->gravity = gravity;
	this->lowestLand = World::FindNearestLand(static_cast<UINT16>(x), static_cast<UINT16>(y));
}




void Character::Update()
{
	lowestLand = World::FindNearestLand(static_cast<UINT16>(x), static_cast<UINT16>(y));

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
	if (GetAsyncKeyState(Up) & 0x8000 || y < lowestLand-DEFAULT_BLOCK_SIZE+10)
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

	if (y >= lowestLand - DEFAULT_BLOCK_SIZE+10)
	{
        y = static_cast<float>(lowestLand - DEFAULT_BLOCK_SIZE+10);
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

