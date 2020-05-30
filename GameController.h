#pragma once

#include "GameLevel.h"
#include "HPTimer.h"

class GameController {
public:
	static inline bool Loading;

	static void Init();
	static void LoadInitialLevel(GameLevel* lev);
	static void SwitchLevel(GameLevel* lev);
	static void UnloadActualLevel();
	static void Render();
	static void Update();


private:
	static inline GameLevel* currentLevel;
	static inline HPTimer* hpTimer;
};
