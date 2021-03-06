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
	background = new Background(Path::backgroundBoard, gfx);
	norbert = new ButtonPaperSheet(Path::bigPaperSheet, gfx, Text::NorbertTasks, {1,1}, { 142, 320 });

	vitalii = new ButtonPaperSheet(Path::bigPaperSheet, gfx, Text::VitTasks, { 2,1 }, { 142,320 });

	pawel = new ButtonPaperSheet(Path::bigPaperSheet, gfx, Text::PawelTasks, { 3,1 }, { 142,320 });

	severyn = new ButtonPaperSheet(Path::bigPaperSheet, gfx, Text::SeverynTasks, { 4, 1 }, { 142,320 });
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

