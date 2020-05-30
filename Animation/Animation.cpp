#include "Animation.h"


Animation::Animation(LPCTSTR bitmapPath, 
					 Graphics* gfx, 
					 GamePoint* position,
					 GameVector* velocity,
					 GameVector* gravity,
					 bool blockPrecision, 
					 UINT16 spriteWidth, 
					 UINT16 spriteHeight ) 
{

	this->position = position;
	this->velocity = velocity;
	this->gravity = gravity;
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->blockPrecision = blockPrecision;
	this->gfx = gfx;
	deltaTime = 0.0;
	sprites = new SpriteSheet(bitmapPath, gfx, spriteWidth, spriteHeight);
}

Animation::~Animation() {

	delete position;
	delete velocity;
	delete gravity;
	delete sprites;
}




void Animation::Update(double timeDelta) {
	this->deltaTime = deltaTime;
}

void Animation::Render() {
	if (blockPrecision) sprites->Draw(index, position->x * spriteWidth, position->y * spriteHeight);
	else sprites->Draw(index, position->x, position->y);
}


void Animation::MoveRight() {
	position->x += velocity->x;
}

void Animation::MoveLeft() {
	position->x -= velocity->x;
}

void Animation::MoveUp() {
	position->y -= velocity->y;
}

void Animation::MoveDown() {
	position->y += velocity->y;
}

void Animation::GravityEvent() {

}