
#include "GameController.h"

bool GameController::Loading;


void GameController::Init() {
	Loading = true;
	currentLevel = 0;
}

void GameController::LoadInitialLevel(GameLevel* lev) {
	Loading = true;
	currentLevel = lev;
	currentLevel->Load();
	Loading = false;
}
void GameController::SwitchLevel(GameLevel* lev) {
	Loading = true;
	currentLevel->Unload();
	lev->Load();
	delete currentLevel;


}

void GameController::Render() {
	if (Loading) return;
	currentLevel->Render();
}

void GameController::Update() {
	if (Loading) return;
	currentLevel->Update();
}

