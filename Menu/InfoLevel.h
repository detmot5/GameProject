#pragma once
#include "../GameLevel.h"
#include "../framework.h"
#include "BackgroundMenu.h"
#include "ButtonPaperSheet.h"
#include "../Text.h"

class InfoLevel : public GameLevel {
public:
	InfoLevel();
	void Load() override;
	void Unload() override;
	void Update() override;
	void Render() override;

private:
	Background* background;
	
	ButtonPaperSheet* norbert;
	ButtonPaperSheet* vitalii;
	ButtonPaperSheet* pawel;
	ButtonPaperSheet* severyn;

	
};