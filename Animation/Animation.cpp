#include "Animation.h"


Animation::Animation(LPCTSTR bitmapPath, Graphics* gfx) {
	this->gfx = gfx;
	x = 0.0;
	y = 0.0;
	xSpeed = 0.0;
	ySpeed = 0.0;
	sprites = new SpriteSheet(bitmapPath, gfx, spriteWidth, spriteHeight);
}

Animation::~Animation() {
	delete sprites;
	delete gfx;
}



void Animation::Update() {

}

void Animation::Render() {

}




void Animation::MoveRight() {

}

void Animation::MoveLeft() {

}

void Animation::MoveUp() {

}

void Animation::MoveDown() {

}
