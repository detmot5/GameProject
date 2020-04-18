#include "GameController.h"
#include "Character.h"
#include "Level1.h"

int Character::temp = 10;

void Character::Jump(Graphics* graphics)
{
	while (Level1::y != 150)
	{
		Level1::y -= 10;

		graphics->BeginDraw();

		GameController::Render();

		graphics->EndDraw();

	}
	if (Level1::y == 150)
	{
		while (Level1::y != 300)
		{
			Level1::y += 10;

			graphics->BeginDraw();

			GameController::Render();

			graphics->EndDraw();
		}
	}
}

void Character::Right(Graphics* graphics)
{
	Level1::change(1);
	GameController::Update();

	graphics->BeginDraw();

	GameController::Render();

	graphics->EndDraw();
}

void Character::Left(Graphics* graphics)
{
	Level1::change(2);

	GameController::Update();

	graphics->BeginDraw();

	GameController::Render();

	graphics->EndDraw();
}

void Character::SinJump_L(Graphics* graphics)
{
	while ((Level1::x < (Level1::x + temp)) && Level1::y != 150)
	{
		Level1::y -= 10;
		Level1::x -= 5, 5;
		graphics->BeginDraw();

		GameController::Render();

		graphics->EndDraw();
	}

	while (Level1::x < (Level1::x + temp) && Level1::y != 300)
	{
		Level1::y += 10;
		Level1::x -= 5, 5;
		graphics->BeginDraw();

		GameController::Render();

		graphics->EndDraw();
	}
}

void Character::SinJump_R(Graphics* graphics)
{
	while ((Level1::x < (Level1::x + temp)) && Level1::y != 150)
	{
		Level1::y -= 10;
		Level1::x += 5, 5;
		graphics->BeginDraw();

		GameController::Render();

		graphics->EndDraw();
	}

	while (Level1::x < (Level1::x + temp) && Level1::y != 300)
	{
		Level1::y += 10;
		Level1::x += 5, 5;
		graphics->BeginDraw();

		GameController::Render();

		graphics->EndDraw();
	}
}