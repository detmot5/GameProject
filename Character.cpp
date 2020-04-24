#include "GameController.h"
#include "Character.h"

#include "GlobalPath.h"

short RaiseIndicator;
short DescentIndicator;

Character::Character(/*LPCWSTR _bitmapPath,*/ Graphics* graphics, float x, float y, float xSpeed, float ySpeed)
{
	this->graphics = graphics;
	this->x = x;
	this->y = y;
	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
	/*bitmapPath = _bitmapPath;*/
	sprites = new SpriteSheet(CharacterPath, this->graphics, 32, 32);
}

void Character::Update()
{
	if (GetKeyState(Right) & 0x8000)
	{
		Right_Move();
	}
	if (GetKeyState(Left) & 0x8000)
	{
		Left_Move();
	}
	if (GetKeyState(Up) & 0x8000 || RaiseIndicator == On || DescentIndicator == On)
	{
		Jump();
	}
}

void Character::Right_Move()
{
	x += xSpeed;

	if (x >= SCREEN_WIDTH)
	{
		x = SCREEN_WIDTH / SCREEN_WIDTH - 1;
	}
}

void Character::Left_Move()
{
	x -= xSpeed;

	if (x <= SCREEN_WIDTH / SCREEN_WIDTH - 1)
	{
		x = SCREEN_WIDTH;
	}
}

void Character::Jump()
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

		if ((y != (int)(SCREEN_HEIGHT * 0.47)) && DescentIndicator == On)
		{
			y += ySpeed;
		}
	}
	if ((y == (int)(SCREEN_HEIGHT *0.47)) && DescentIndicator == On)
	{
		DescentIndicator = Off;
	}
}

void Character::Render()
{
	sprites->Draw((1 / 10) % 1, x, y);
}