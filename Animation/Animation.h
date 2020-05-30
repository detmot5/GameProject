#pragma once

#include "../framework.h"
#include "../SpriteSheet.h"
#include "../Graphics.h"
#include "../World.h"
#include "GameVector.h"

class Animation
{
public:
	Animation(LPCTSTR, Graphics*, GamePoint*, GameVector*, GameVector*, bool, UINT16 = DEFAULT_BLOCK_SIZE, UINT16 = DEFAULT_BLOCK_SIZE);
	~Animation();


	virtual void Update(double timeDelta);
	virtual void Render();


	virtual void MoveRight();
	virtual void MoveLeft();
	virtual void MoveUp();
	virtual void MoveDown();
	
	void GravityEvent();


protected:
	int position;



	GamePoint* position;
	GameVector* velocity;
	GameVector* gravity;
	double deltaTime;



	int index;
	bool blockPrecision;

	UINT16 spriteWidth, spriteHeight;
	SpriteSheet* sprites;

	Graphics* gfx;
};

