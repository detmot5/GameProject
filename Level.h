#pragma once

#include "GameLevel.h"
#include "Block.h"
#include "World.h"


class Level : public GameLevel
{
public:

	void Load() override;
	void Unload() override;
	void Render() override;
	void Update() override;

private:
	int frame;
	float y;
	float ySpeed;
	Block* block;
	SpriteSheet* sprites;

};

