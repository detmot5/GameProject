#include "Menu.h"
#include "../GameController.h"


Menu::Menu() {
	this->gfx = gfx;
	bg = 0;
	bm = 0;
	bm2 = 0;
}

void Menu::Load() {
	bg = new Background(L"GameProject/Graphicss/BackgroundMenu.png", gfx);
	bm = new ButtonMenu(L"GameProject/Graphicss/ButtonPlay.png", gfx, 340, UserInput::PlayOnClick);
	bm2 = new ButtonMenu(L"GameProject/Graphicss/ButtonInfo.png",gfx, 50, UserInput::InfoOnClick);

}


void Menu::Unload() {
	delete bg;
	delete bm;
	delete bm2;
}


void Menu::Update() {
	bm->OnClickEvent();
	bm2->OnClickEvent();

}


void Menu::Render() {
	gfx->ClearScreen(0, 0, 0);
	bg->Render();
	bm->Render();
	bm2->Render();
	
}


