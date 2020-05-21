#include "Animation.h"


Animation::Animation(LPCTSTR bitmapPath, Graphics* gfx, bool blockPrecision, UINT16 spriteWidth, UINT16 spriteHeight) {
	x = 0;
	y = 0;
	xSpeed = 0;
	ySpeed = 0;
	jumpHeight = 0.0;
	gravity = 0.0;
	index = 0;
	position = 0;
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
	if (blockPrecision) sprites->Draw(index, x * spriteWidth, y * spriteHeight);
	else sprites->Draw(index, position, y - 24);
}




void Animation::MoveRight() {
	x += static_cast<int>(xSpeed);

	if (x >= SCREEN_WIDTH)
	{
		x = SCREEN_WIDTH / SCREEN_WIDTH - 1;
	}
}

void Animation::MoveLeft() {
	x -= static_cast<int>(xSpeed);

	if (x <= SCREEN_WIDTH / SCREEN_WIDTH - 1)
	{
		x = SCREEN_WIDTH;
	}
}

void Animation::MoveUp() {
	y -= static_cast<int>(ySpeed);

	if (y <= SCREEN_HEIGHT / SCREEN_HEIGHT - 1)
	{
//		y = (World::GetAverageFloorLevel() * 30);
	}
}

void Animation::MoveDown() {
	y += static_cast<int>(ySpeed);

	if (y >= SCREEN_HEIGHT)
	{
	//	y = (World::GetAverageFloorLevel() * 30);
	}
}