#pragma once
#include "Graphics.h"
#include "SpriteSheet.h"

class ButtonMenu {
public:
	ButtonMenu(LPCTSTR bitmapPath, Graphics* gfx, short ButtonOffset, void (*OnClickCallback)());
	void Render();
	void OnClickEvent();

private:
	Graphics* gfx;
	SpriteSheet* sprites;
	short ButtonOffset;
	void (*OnClickCallback)();
};