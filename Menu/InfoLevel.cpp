#include "../GameController.h"
#include "InfoLevel.h"

InfoLevel::InfoLevel() {
	this->gfx = gfx;
	background = 0;
	norbert = 0;
	severyn = 0;
	pawel = 0;
	vitalii = 0;
}

void InfoLevel::Load() {
	background = new Background(L"GameProject/Graphicss/BackGroundInfoButton.png", gfx);
	norbert = new ButtonPaperSheet(L"GameProject/Graphicss/PaperSheet.png", gfx, L"Norbert ", 1);

	vitalii = new ButtonPaperSheet(L"GameProject/Graphicss/PaperSheet.png", gfx, L"Vitalii", 2);

	pawel = new ButtonPaperSheet(L"GameProject/Graphicss/PaperSheet.png", gfx, L"Pawel", 3);

	severyn = new ButtonPaperSheet(L"GameProject/Graphicss/PaperSheet.png", gfx, L"Igor", 4);
}

void InfoLevel::Unload() {

}

void InfoLevel::Update(){

}

void InfoLevel::Render() {
	gfx->ClearScreen(0, 0, 0);
	background->Render();
	norbert->Render();

	vitalii->Render();

	pawel->Render();

	severyn->Render();
	

}

