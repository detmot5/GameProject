#pragma once
#include "../Graphics.h"
#include "../SpriteSheet.h"

class Background {
public:
	Background(LPCTSTR bitmapPath, Graphics* gfx);
	void Render();



private:
	Graphics* gfx;
	SpriteSheet* sprites;

};