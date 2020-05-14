#include "Menu.h"
#include "GameController.h"

Menu::Menu() {
	this->gfx = gfx;

}


void Menu::Load() {
	bg = new Background(L"BackgroundMenu.png", gfx);
	bm = new ButtonMenu(L"ButtonPlay.png", gfx, 200, UserInput::PlayOnClick);
	bm2 = new ButtonMenu(L"ButtonInfo.png", gfx, 110, UserInput::InfoOnClick);
}


void Menu::Unload() {

}


void Menu::Update() {
	if (UserInput::butt & MK_LBUTTON) bm->OnClickEvent();
	if (GetAsyncKeyState(VK_SHIFT)) bm2->OnClickEvent();

}


void Menu::Render() {
	gfx->ClearScreen(0, 0, 0);
	bg->Render();
	bm->Render();
	bm2->Render();
	
}


