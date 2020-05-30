#pragma once
#include "../Graphics.h"
#include "../SpriteSheet.h"
#include "UserInput.h"

class ButtonMenu {
public:
	ButtonMenu(LPCTSTR bitmapPath, Graphics* gfx, short ButtonOffset);
	void Render();
	void OnClickEvent();
	bool IsCursorOnButton();
	void RegisterOnClickCallback(void (*callback)());


	static inline int flag = 0;

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