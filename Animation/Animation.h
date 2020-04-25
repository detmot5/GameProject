#pragma once

#include "../framework.h"
#include "../SpriteSheet.h"
#include "../Graphics.h"

class Animation
{
public:
	Animation(LPCTSTR, Graphics*);
	~Animation();

	virtual void Update();
	virtual void Render();


	virtual void MoveRight();
	virtual void MoveLeft();
	virtual void MoveUp();
	virtual void MoveDown();


protected:
	float x, y;
	float xSpeed, ySpeed;
	UINT16 spriteWidth, spriteHeight;
	SpriteSheet* sprites;
	Graphics* gfx;


};
