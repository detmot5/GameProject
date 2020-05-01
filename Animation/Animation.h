#pragma once

#include "../framework.h"
#include "../SpriteSheet.h"
#include "../Graphics.h"
#include "../World.h"

class Animation
{
public:
	Animation(LPCTSTR, Graphics*, bool, UINT16 = DEFAULT_BLOCK_SIZE, UINT16 = DEFAULT_BLOCK_SIZE);
	~Animation();


	virtual void Update() = 0;
	virtual void Render();


	virtual void MoveRight();
	virtual void MoveLeft();
	virtual void MoveUp();
	virtual void MoveDown();


protected:
	float x, y;
	float xSpeed, ySpeed;

	float jumpHeight;
	float gravity;

	short index;
	bool blockPrecision;

	UINT16 spriteWidth, spriteHeight;
	SpriteSheet* sprites;

	Graphics* gfx;
};

