#pragma once
#include <wincodec.h>		// decoding image from file
#include "Graphics.h"


class SpriteSheet {
public:
	SpriteSheet(LPCWSTR filename, Graphics* gfx);
	SpriteSheet(LPCWSTR filename, Graphics* gfx, int spriteWidth, int spriteHeight);
	
	~SpriteSheet();
		//draw bitmap to the render target
	void Draw();
	void Draw(int index, int x, int y);
private:
	
	Graphics* gfx;
	ID2D1Bitmap* buttonPlayp;		//Bitmap loaded file and converted to Direct2D format
	int spriteWidth, spriteHeight;
	int spritesAccross;
};
