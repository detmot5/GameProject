#include "ButtonMenu.h"

ButtonMenu::ButtonMenu(LPCTSTR bitmapPath, Graphics* gfx, short ButtonOffset, void(*OnClickCallback)()) {
	this->gfx = gfx;
	this->ButtonOffset = ButtonOffset;
	this->OnClickCallback = OnClickCallback;
	this->spriteWidth = 190;
	this->spriteHeight = 109;

	sprites = new SpriteSheet(bitmapPath, gfx, spriteWidth, spriteHeight);
}
void ButtonMenu::Render() {
	sprites->Draw(0, (SCREEN_WIDTH/2)-95, (SCREEN_HEIGHT/2)-ButtonOffset);
}
void ButtonMenu::OnClickEvent() {
	if (OnClickCallback) OnClickCallback();
}