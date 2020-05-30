
#include "GameController.h"




void GameController::Init() {
	Loading = true;
	currentLevel = 0;
	hpTimer = new HPTimer();
	
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
	currentLevel = lev;
	Loading = false;
}

void GameController::UnloadActualLevel() {
	Loading = true;
	currentLevel->Unload();
	delete currentLevel;
	Loading = false;
}

void GameController::Render() {
	if (Loading) return;
	currentLevel->Render();
	hpTimer->Update();
}

void GameController::Update() {
	if (Loading) return;
	hpTimer->Update();
	currentLevel->Update(hpTimer->GetTimeTotal(), hpTimer->GetTimeDelta());
}

