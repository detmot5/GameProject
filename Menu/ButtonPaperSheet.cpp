#include "ButtonPaperSheet.h"

ButtonPaperSheet::ButtonPaperSheet(LPCTSTR bitmapPath, Graphics* gfx, const WCHAR* str, UINT8 multiplier, short offset) {
	this->gfx = gfx;
	this->offset = offset;



	this->multiplier = multiplier;

	this->str = str;

	this->xCord = multiplier * offset;

	this->yCord = (SCREEN_HEIGHT / 4);

	sprites = new SpriteSheet(bitmapPath, gfx, spriteWidth, spriteHeight);

	rect.top = (yCord+spriteWidth);
	rect.bottom = yCord;
	rect.left = xCord;
	rect.right = (xCord + spriteWidth)-(spriteWidth/4);
}

ButtonPaperSheet::~ButtonPaperSheet() {
	delete sprites;
}

void ButtonPaperSheet::Render() {
	sprites->Draw(0, xCord-30, yCord-15);
	gfx->Print(str, rect, 18, L"Gabriola");

}
