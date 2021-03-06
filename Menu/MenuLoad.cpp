#include "MenuLoad.h"

MenuLoad::MenuLoad()
{
	released = false;
}

MenuLoad::~MenuLoad()
{
}



void MenuLoad::Load() {
	background = new Background(Path::backgroundBoard, gfx);
	saves = GameSaver::GetAllSaves();

	
	for (UINT8 i = 0, j = 1,k = 1; i < saves.size(); i++, k++) {
		if (i > 0 && !(i % 4)) {
			j++;
			k = 1;
		}
		sheets.push_back(new ButtonPaperSheet(Path::bigPaperSheet, gfx, saves[i].c_str(), { k ,j }, { 142,150 },18,LoadLevel));
	}



}


void MenuLoad::Unload() {
	delete background;
	sheets.clear();

}

void MenuLoad::Update() {

	if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) released = true;
	if(released) for (auto i : sheets) i->OnClickEvent();
}

void MenuLoad::Render() {
	background->Render();
	for (auto i : sheets) i->Render();
}

void MenuLoad::LoadLevel(const WCHAR* path) {
	GameController::SwitchLevel(new Level(Level::LoadSave, path));
}