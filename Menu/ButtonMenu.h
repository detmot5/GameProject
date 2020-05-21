#pragma once
#include "../Graphics.h"
#include "../SpriteSheet.h"
#include "UserInput.h"

class ButtonMenu {
public:
	ButtonMenu(LPCTSTR bitmapPath, Graphics* gfx, short ButtonOffset, void (*callback)());
	~ButtonMenu();
	void Render();
	void OnClickEvent();

	bool IsCursorOnButton();
private:
	Graphics* gfx;
	SpriteSheet* sprites;
	short spriteWidth;
	short spriteHeight;
	short ButtonOffset;
	void (*OnClickCallback)();
	short xCord;
	short yCord;

};