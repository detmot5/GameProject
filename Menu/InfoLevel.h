#pragma once
#include "../GameLevel.h"
#include "../framework.h"
#include "ContentInfo.h"
#include "../Level.h"

class InfoLevel : public GameLevel {
public:
	InfoLevel();
	void Load() override;
	void Unload() override;
	void Update() override;
	void Render() override;

private:
	ContentInfo* continfo;



};