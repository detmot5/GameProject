#pragma once
#include "../Graphics.h"
#include "../SpriteSheet.h"


class ButtonPaperSheet {
public:
	ButtonPaperSheet(LPCTSTR bitmapPath, Graphics* gfx, const WCHAR* str, UINT8 multiplier, short offset = 142);
	~ButtonPaperSheet();
	void Render();

private:
	Graphics* gfx;
	SpriteSheet* sprites;

	static inline short spriteWidth = 142;
	static inline short spriteHeight = 280;

	short offset;

	D2D_RECT_F rect;

	UINT8 multiplier;

	const WCHAR* str;

	short xCord;
	short yCord;

};