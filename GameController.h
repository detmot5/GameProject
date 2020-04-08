#pragma once

#include "GameLevel.h"

class GameController {
public:
	static bool Loading;

	static void Init();
	static void LoadInitialLevel(GameLevel* lev);
	static void SwitchLevel(GameLevel* lev);
	static void Render();
	static void Update();


private:
	GameController() {}
	inline static GameLevel* currentLevel;
};
