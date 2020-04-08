#pragma once
#include "Graphics.h"
#include "SpriteSheet.h"

class GameLevel {
public:

	static void InitGraphics(Graphics* graphics) {
		gfx = graphics;
	}

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

protected:
	static inline Graphics* gfx;
};