#pragma once

#include "Graphics.h"

class Character
{
public:
	Character(/*LPCWSTR _bitmapPath,*/ Graphics* graphics, float xSpeed = 4.0, float ySpeed = 4);

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
		raise = 2,
		down = 1
	};

	struct Vector
	{
		float x;
		float y;
	}vector;

	struct Point
	{
		float x;
		float y;
	}point;

	SpriteSheet* sprites;
	static inline Graphics* graphics;
	/*static LPCWSTR bitmapPath;*/
};