#pragma once
#include "../Graphics.h"
#include "../SpriteSheet.h"
#include "UserInput.h"

class ButtonMenu {
public:
	ButtonMenu(LPCTSTR bitmapPath,LPCTSTR clickedBitmap, Graphics* gfx, short ButtonOffset, void (*callback)());
	~ButtonMenu();
	void Render();
	void OnClickEvent();

	bool IsCursorOnButton();
	static inline int flag = 0;
private:
	Graphics* gfx;
	SpriteSheet* sprites;
	SpriteSheet* clickedSprite;
	short spriteWidth;
	short spriteHeight;
	short ButtonOffset;
	void (*OnClickCallback)();
	short xCord;
	short yCord;

};