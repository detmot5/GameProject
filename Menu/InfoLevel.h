#pragma once
#include "../GameLevel.h"
#include "../framework.h"
#include "../Level.h"
#include "BackgroundMenu.h"

class InfoLevel : public GameLevel {
public:
	InfoLevel();
	void Load() override;
	void Unload() override;
	void Update() override;
	void Render() override;

private:
	Background* background;
	D2D_RECT_F rect;


};