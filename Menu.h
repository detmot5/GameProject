#pragma once
#include "GameLevel.h"
#include "Graphics.h"
#include "framework.h"
#include "BackgroundMenu.h"
#include "ButtonMenu.h"
#include "Level.h"
#include "UserInput.h"


class Menu : public GameLevel {
public:
	Menu();
	void Load() override;
	void Unload() override;
	void Update() override;
	void Render() override;

private:
	Background* bg;
	ButtonMenu* bm;
	ButtonMenu* bm2;
};