#include "GameController.h"
#include "Character.h"
#include "Buttons.h"

Graphics* Character::graphics;
SpriteSheet* Character::sprites;
short inline flaga = 0;

struct Character::Vector vector;
struct Character::Point point;

void Character::Init(/*LPCWSTR _bitmapPath,*/ Graphics* _graphics, float x, float y, float xSpeed, float ySpeed)
{
	graphics = _graphics;
	point.x = x;
	point.y = y;
	vector.x = xSpeed;
	vector.y = ySpeed;
	/*bitmapPath = _bitmapPath;*/
	sprites = new SpriteSheet(L"GameProject/Graphicss/Graphicss/test.png", graphics, 64, 64);
}

void Character::move()
{
	if (GetKeyState(Right) & 0x8000)
	{
		point.x += vector.x;

		if (point.x >= 800)
		{
			point.x = 0;
		}
	}
	if (GetKeyState(Left) & 0x8000)
	{
		point.x -= vector.x;

		if (point.x <= 0)
		{
			point.x = 750;
		}
	}
	if (GetKeyState(Up) & 0x800 || flaga == 1 || flaga == 2)
	{

		if ((point.y != 156 && flaga == 0) || flaga == 2)
		{
			point.y -= 4;
			flaga = 2;
		}
		if (point.y == 156 || flaga == 1)
		{
			flaga = 1;
			if (point.y != 268 && flaga == 1)
			{
				point.y += 4;
			}
		}
		if (point.y == 268 && flaga == 1)
		{
			flaga = 0;
		}
	}
}


void Character::Render()
{
	sprites->Draw((1 / 10) % 1, point.x, point.y);
}