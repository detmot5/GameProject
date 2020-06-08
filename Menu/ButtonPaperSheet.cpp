#include "ButtonPaperSheet.h"

ButtonPaperSheet::ButtonPaperSheet(LPCTSTR bitmapPath, Graphics* gfx, const WCHAR* str, POINT pos,POINT spriteSize, int font , void (*onClick)(const WCHAR*)) {
	this->gfx = gfx;

	this->font = font;

	this->multiplier = multiplier;

	this->str = str;
	this->spriteWidth = spriteSize.x;
	this->spriteHeight = spriteSize.y;
	this->offset = spriteWidth;
	this->callback = onClick;
	this->xCord = pos.x * offset;

	this->yCord = (SCREEN_HEIGHT / 4) * pos.y;

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
	gfx->Print(str, rect, font, L"Gabriola");

}
void ButtonPaperSheet::OnClickEvent() {
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && IsCursorOnButton()) {
		if (callback) callback(str);
	}
}


bool ButtonPaperSheet::IsCursorOnButton() {

	if (UserInput::GetCursorPos().x >= xCord && UserInput::GetCursorPos().x <= xCord + spriteWidth &&
		UserInput::GetCursorPos().y >= yCord && UserInput::GetCursorPos().y <= yCord + spriteHeight) {
		return true;
	}

	return false;
}
