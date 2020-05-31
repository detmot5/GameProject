#include "../GameController.h"
#include "InfoLevel.h"

InfoLevel::InfoLevel() {
	this->gfx = gfx;
	continfo = 0;
}

void InfoLevel::Load() {
	continfo = new ContentInfo(L"GameProject/Graphicss/BackGroundInfoButton.png", gfx);
}

void InfoLevel::Unload() {

}

void InfoLevel::Update(){

}

void InfoLevel::Render() {
	gfx->ClearScreen(0, 0, 0);
	continfo->Render();

}


