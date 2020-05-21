#include "ButtonMenu.h"

ButtonMenu::ButtonMenu(LPCTSTR bitmapPath, Graphics* gfx, short ButtonOffset, void(*OnClickCallback)()) {
	this->gfx = gfx;
	this->ButtonOffset = ButtonOffset;
	this->OnClickCallback = OnClickCallback;
	this->spriteWidth = 190;
	this->spriteHeight = 109;
	this->xCord = (SCREEN_WIDTH / 2) - 95;
	this->yCord = (SCREEN_HEIGHT / 2) - ButtonOffset;

	sprites = new SpriteSheet(bitmapPath, gfx, spriteWidth, spriteHeight);
}
void ButtonMenu::Render() {
	sprites->Draw(0, xCord, yCord);
}
void ButtonMenu::OnClickEvent() {
	if (IsCursorOnButton() && GetAsyncKeyState(VK_LBUTTON) & 0x8000) {

		if (OnClickCallback) OnClickCallback();
	}
	if (IsCursorOnButton() && GetAsyncKeyState(VK_LBUTTON) & 0x8000) {

		if (OnClickCallback) OnClickCallback();
	}
	
}
bool ButtonMenu::IsCursorOnButton() {
	if (UserInput::GetCursorPos().x >= xCord && UserInput::GetCursorPos().x <= xCord + spriteWidth &&
		UserInput::GetCursorPos().y >= yCord && UserInput::GetCursorPos().y <= yCord + spriteHeight) {

		return true;
	}
	return false;
}
