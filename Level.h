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

};

