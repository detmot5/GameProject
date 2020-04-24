#pragma once

#include "Graphics.h"

class Character
{
public:
	Character(/*LPCWSTR _bitmapPath,*/ Graphics* graphics, float x = SCREEN_WIDTH * 0.5, float y = (int)(SCREEN_HEIGHT * 0.47), float xSpeed = 4.0, float ySpeed = 4);

	void Update();
	void Render();

private:
	void Right_Move();
	void Left_Move();
	void Jump();

	enum Direction
	{
		Right = 'D',
		Left = 'A',
		Up = 0x20
	};

	enum indicator
	{
		On = 1,
		Off = 0
	};
	
	float x;
	float y;

	float xSpeed;
	float ySpeed;

	SpriteSheet* sprites;
	static inline Graphics* graphics;
	/*static LPCWSTR bitmapPath;*/
};