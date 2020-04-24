#include "GameController.h"
#include "Character.h"

#include "GlobalPath.h"

short flag = NULL;

Character::Character(/*LPCWSTR _bitmapPath,*/ Graphics* graphics, float xSpeed, float ySpeed)
{
	this->graphics = graphics;
	point.x = SCREEN_WIDTH * 0.5;
	point.y = (int)(SCREEN_HEIGHT * 0.47);
	vector.x = xSpeed;
	vector.y = ySpeed;
	/*bitmapPath = _bitmapPath;*/
	sprites = new SpriteSheet(Path.Character, this->graphics, 32, 32);
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
	if (GetKeyState(Up) & 0x8000 || flag == down || flag == raise)
	{
		Jump();
	}
}

void Character::Right_Move()
{
	point.x += vector.x;

	if (point.x >= SCREEN_WIDTH)
	{
		point.x = SCREEN_WIDTH / SCREEN_WIDTH - 1;
	}
}

void Character::Left_Move()
{
	point.x -= vector.x;

	if (point.x <= SCREEN_WIDTH / SCREEN_WIDTH - 1)
	{
		point.x = SCREEN_WIDTH;
	}
}

void Character::Jump()
{
	if ((point.y != (int)(SCREEN_HEIGHT * 0.27) && flag == NULL) || flag == raise)
	{
		point.y -= vector.y;
		flag = raise;
	}
	if (point.y == (int)(SCREEN_HEIGHT * 0.27) || flag == down)
	{
		flag = down;
		if ((point.y != (int)(SCREEN_HEIGHT * 0.47)) && flag == down)
		{
			point.y += vector.y;
		}
	}
	if ((point.y == (int)(SCREEN_HEIGHT *0.47)) && flag == down)
	{
		flag = NULL;
	}
}

void Character::Render()
{
	sprites->Draw((1 / 10) % 1, point.x, point.y);
}