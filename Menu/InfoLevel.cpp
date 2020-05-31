#include "../GameController.h"
#include "InfoLevel.h"

InfoLevel::InfoLevel() {
	this->gfx = gfx;
	background = 0;
	rect.top = 300;
	rect.bottom = 400;
	rect.left = 200;
	rect.right = 300;
}

void InfoLevel::Load() {
	background = new Background(L"GameProject/Graphicss/BackGroundInfoButton.png", gfx);
}

void InfoLevel::Unload() {

}

void InfoLevel::Update(){

}

void InfoLevel::Render() {
	gfx->ClearScreen(0, 0, 0);
	background->Render();
	gfx->Print(L"Siema", rect, 25, L"Gabriola");

}

