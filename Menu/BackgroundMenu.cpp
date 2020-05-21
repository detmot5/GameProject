#include "BackgroundMenu.h"


Background::Background(LPCTSTR bitmapPath, Graphics* gfx) {
	this->gfx=gfx;
	sprites = new SpriteSheet(bitmapPath, gfx, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void Background::Render() {
	sprites->Draw();
}