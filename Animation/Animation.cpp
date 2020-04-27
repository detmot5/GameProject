#include "Animation.h"


Animation::Animation(LPCTSTR bitmapPath, Graphics* gfx, bool blockPrecision, UINT16 spriteWidth, UINT16 spriteHeight) {
	x = 0.0;
	y = 0.0;
	xSpeed = 0.0;
	ySpeed = 0.0;
	height = 0.0;
	gravity = 0.0;
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->blockPrecision = blockPrecision;
	this->gfx = gfx;
	sprites = new SpriteSheet(bitmapPath, gfx, spriteWidth, spriteHeight);
}

Animation::~Animation() {
	delete sprites;
	delete gfx;
}



void Animation::Update() {

}

void Animation::Render() {
	if(blockPrecision) sprites->Draw(index, x*spriteWidth, y*spriteHeight);
	else sprites->Draw(index, x, y);
}




void Animation::MoveRight() {
	x += xSpeed;

	if (x >= SCREEN_WIDTH)
	{
		x = SCREEN_WIDTH / SCREEN_WIDTH - 1;
	}
}

void Animation::MoveLeft() {
	x -= xSpeed;

	if (x <= SCREEN_WIDTH / SCREEN_WIDTH - 1)
	{
		x = SCREEN_WIDTH;
	}
}

void Animation::MoveUp() {
	y = y + height * ySpeed;

	height = height + gravity * ySpeed;

	if (y >= 300)
	{
		height = 20;
		y = 300;
	}
}

void Animation::MoveDown() {

}

void Animation::ChangeSprite()
{
	
}
