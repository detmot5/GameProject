#pragma once
#include <vector>
#include "Graphics.h"
#include "SpriteSheet.h"
#include "Animation/Animation.h"

class GameLevel {
public:

	static void InitGraphics(Graphics* graphics) {
		gfx = graphics;
	}

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Update(double timeTotal, double timeDelta) = 0;
	virtual void Render() = 0;

protected:
	static inline Graphics* gfx;
	std::vector<Animation*> Animations;
};