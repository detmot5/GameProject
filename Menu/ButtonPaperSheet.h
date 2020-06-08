#pragma once
#include "../Graphics.h"
#include "../SpriteSheet.h"
#include "UserInput.h"

class ButtonPaperSheet {
public:
	ButtonPaperSheet(LPCTSTR bitmapPath, Graphics* gfx, const WCHAR* str, POINT pos, POINT spriteSize, int font = 18, void (*onClick)(const WCHAR*) = nullptr);
	~ButtonPaperSheet();
	void Render();
	void OnClickEvent();


private:
	Graphics* gfx;
	SpriteSheet* sprites;

	short spriteWidth = 142;
	short spriteHeight = 134;

	short offset;

	D2D_RECT_F rect;

	UINT8 multiplier;

	const WCHAR* str;
	int font;
	short xCord;
	short yCord;
	void (*callback)(const WCHAR*);



	bool IsCursorOnButton();
};