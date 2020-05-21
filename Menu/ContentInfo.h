#pragma once
#include "../Graphics.h"
#include "../SpriteSheet.h"

class ContentInfo {
public:
	ContentInfo(LPCTSTR btmapPath, Graphics* gfx);
	void Render();



private:
	Graphics* gfx;
	SpriteSheet* sprites;

};