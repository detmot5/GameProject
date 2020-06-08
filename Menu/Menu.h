#pragma once
#include "../GameLevel.h"
#include "../framework.h"
#include "BackgroundMenu.h"
#include "ButtonMenu.h"
#include <thread>
#include "ButtonsCallbacks.h"

class Menu : public GameLevel {
public:
	Menu();
	~Menu();
	void Load() override;
	void Unload() override;
	void Update() override;
	void Render() override;

private:
	Background* backGroundMenu;
	ButtonMenu* buttonPlay;
	ButtonMenu* buttonPlayDark;
	ButtonMenu* buttonInfo;
	ButtonMenu* buttonInfoDark;
	ButtonMenu* buttonLoad;
	ButtonMenu* buttonLoadDark;


};