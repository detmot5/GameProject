#include "GameController.h"
#include "Character.h"


Character::Character(LPCTSTR bitmapPath, Graphics* graphics, int position, int y, float xSpeed,
	float ySpeed, float jumpHeight, float gravity)
	: Animation(bitmapPath, graphics, false)
{
	this->position = position;
	this->x = position;
	this->y = World::FindNearestLandY(x, 0);
	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
	this->jumpHeight = jumpHeight;
	this->gravity = gravity;
}

bool flag = false;


void Character::Update()
{

	if (flag != true)
	{
		//y = World::FindNearestLandY(x, y);
	}
	

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
	if (GetAsyncKeyState(Up) & 0x8000 || (World::actualChunk->isCollisionEnabled(x /32, y / 32) && flag == true))
	{
		//MoveUp();
	}
}

void Character::Render()
{
	Animation::Render();

}




void Character::MoveUp()
{
	if (World::actualChunk->isCollisionEnabled(x / 32, (y - 64) / 32))
	{

		
			flag = true;
			y += static_cast<int>(jumpHeight * ySpeed);

			jumpHeight += gravity * ySpeed;

			if (y >= World::FindNearestLandY(x, y))
			{
				y = World::FindNearestLandY(x, y);
				jumpHeight = 25;

				flag = false;
			}
			
	}
	
}

void Character::MoveRight()
{
	index = 1;
	
	 World::offset += 10;
	if (World::FindNearestWall(x, y))
	{
		//x = abs(World::offset) - World::actualChunk->GetStartPoint()*32;
	}
}

void Character::MoveLeft()
{
	index = 2;
	if (World::offset / 32 > World::chunks.front()->GetStartPoint()) World::offset -= 10;

	//x -= 7;

}

