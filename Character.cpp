#include "GameController.h"
#include "Character.h"
#include "World.h"

short RaiseIndicator;
short DescentIndicator;

Character::Character(LPCTSTR bitmapPath, Graphics* graphics, float x, float y, float xSpeed, float ySpeed)
	: Animation(bitmapPath, graphics, false)
{
	//this->graphics = graphics;
	this->x = x;
	this->y = y;
	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
	/*bitmapPath = _bitmapPath;*/
	/*sprites = new SpriteSheet(L"../GameProject/Graphicss/slime_sprite.png", this->graphics, 32, 32);*/
}

void Character::Update()
{
	MoveRight();

	MoveLeft();

	MoveUp();
}

void Character::MoveRight()
{
	if (GetKeyState(Right) & 0x8000)
	{
		x += xSpeed;

		if (x >= SCREEN_WIDTH)
		{
			x = SCREEN_WIDTH / SCREEN_WIDTH - 1;
		}
	}
}

void Character::MoveLeft()
{
	if (GetKeyState(Left) & 0x8000)
	{
		x -= xSpeed;

		if (x <= SCREEN_WIDTH / SCREEN_WIDTH - 1)
		{
			x = SCREEN_WIDTH;
		}
	}
}

void Character::MoveUp()
{
	if (GetKeyState(Up) & 0x8000 || RaiseIndicator == On || DescentIndicator == On)
	{
		if ((y != (int)(SCREEN_HEIGHT * 0.27) && DescentIndicator == Off) || RaiseIndicator == On)
		{
			y -= ySpeed;
			RaiseIndicator = On;
		}
		if (y == (int)(SCREEN_HEIGHT * 0.27) || DescentIndicator == On)
		{
			RaiseIndicator = Off;
			DescentIndicator = On;

			if ((y >= World::GetFloorLever()) && DescentIndicator == On)
			{
				y += ySpeed;
			}
			
		}
		if ((y == (int)(SCREEN_HEIGHT * 0.47)) && DescentIndicator == On)
		{
			//ySpeed = 0;
			DescentIndicator = Off;
		}
	}
}

void Character::MoveDown()
{
	
}

void Character::Render()
{
	sprites->Draw((1 / 10) % 1, x, y);
}