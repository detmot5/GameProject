#pragma once

#include "GameLevel.h"



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
	SpriteSheet* sprites;

};

