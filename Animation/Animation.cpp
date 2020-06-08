#include "Animation.h"


Animation::Animation(LPCTSTR bitmapPath, 
					 Graphics* gfx, 
					 GameVector* position,
					 GameVector* velocity,
					 GameVector* gravity,
					 bool blockPrecision, 
					 UINT16 spriteWidth, 
					 UINT16 spriteHeight ) 
{

	this->position = position;
	this->velocity = velocity;
	this->gravity = gravity;
	this->index = 0;
	this->timeDelta = 0.0;
	sprites = new SpriteSheet(bitmapPath, gfx, spriteWidth, spriteHeight);
}

Animation::~Animation() {

	delete position;
	delete velocity;
	delete gravity;
	delete sprites;
}




void Animation::Update() {
	this->timeDelta = timeDelta;
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
	position->y = position->y + velocity->y * 0.008f;
	velocity->y = velocity->y + gravity->y;

}

