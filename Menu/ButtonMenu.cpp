#include "ButtonMenu.h"

ButtonMenu::ButtonMenu(LPCTSTR bitmapPath, Graphics* gfx, short ButtonOffset, void (*callback)()) {
	this->gfx = gfx;
	this->ButtonOffset = ButtonOffset;
	this->spriteWidth = 190;
	this->spriteHeight = 109;
	this->OnClickCallback = callback;
	this->xCord = (SCREEN_WIDTH / 2) - 95;
	this->yCord = (SCREEN_HEIGHT / 2) - ButtonOffset;


	sprites = new SpriteSheet(bitmapPath, gfx, spriteWidth, spriteHeight);
}
ButtonMenu::~ButtonMenu() {
	OnClickCallback = 0;
	delete sprites;
}


void ButtonMenu::Render() {
	sprites->Draw(0, xCord, yCord);
}

void ButtonMenu::OnClickEvent() {


	if (UserInput::GetCursorPos().x >= xCord && UserInput::GetCursorPos().x <= xCord + spriteWidth)
	{	
		if (UserInput::GetCursorPos().y >= yCord && UserInput::GetCursorPos().y <= yCord + spriteHeight)
		{
			flag = 1;
		}
		if (UserInput::GetCursorPos().y >= 210 && UserInput::GetCursorPos().y <= 210 + spriteHeight)
			flag = 2;
		if (UserInput::GetCursorPos().y >= 300 && UserInput::GetCursorPos().y <= 300 + spriteHeight)
			flag = 3;
	}
	else
	{
		flag = 0;
	}

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && IsCursorOnButton()) {
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
