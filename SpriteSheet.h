#pragma once
#include <wincodec.h>		// decoding image from file
#include "Graphics.h"


class SpriteSheet {
public:
	SpriteSheet(LPCWSTR filename, Graphics* gfx);
	SpriteSheet(LPCWSTR filename, Graphics* gfx, float spriteWidth, float spriteHeight);

	~SpriteSheet();
	//draw bitmap to the render target
	void Draw();
	void Draw(int index, float x, float y);
private:

	Graphics* gfx;
	ID2D1Bitmap* bmp;		//Bitmap loaded file and converted to Direct2D format
	float spriteWidth, spriteHeight;
	int spritesAccross;
};