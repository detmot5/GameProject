#pragma once

#include "Graphics.h"


class Character
{
public:
	void static Init(/*LPCWSTR _bitmapPath,*/ Graphics* _graphics, float x = 0, float y = 268, float xSpeed = 2.0, float ySpeed = 0);
	void static move();
	void static Render();
	static struct Vector
	{
		float x;
		float y;
	};

	static struct Point
	{
		float x;
		float y;
	};
private:
	static SpriteSheet* sprites;
	static Graphics* graphics;
	/*static LPCWSTR bitmapPath;*/
};