#pragma once

#include <vector>

#include "GameLevel.h"
#include "Block.h"
#include "World.h"

#include "Animation/Animation.h"
#include "Character.h"
#include "Clouds.h"


class Level : public GameLevel
{
public:
<<<<<<< HEAD
	Level(wstring path, bool load);
=======
	Level();
	Level(wstring path);
>>>>>>> menu
	~Level();

	void Load() override;
	void Unload() override;
	void Render() override;
	void Update() override;

<<<<<<< HEAD
	enum {
		NewSave = false,
		LoadSave = true,
	};
=======
>>>>>>> menu

private:
	bool load;
	wstring path;
};

