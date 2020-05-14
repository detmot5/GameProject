#pragma once

#include <vector>

#include "GameLevel.h"
#include "Block.h"
#include "World.h"
#include "Menu.h"

#include "Animation/Animation.h"
#include "Character.h"
#include "Clouds.h"


class Level : public GameLevel
{
public:

	void Load() override;
	void Unload() override;
	void Render() override;
	void Update() override;
};

