#include "ContentInfo.h"


ContentInfo::ContentInfo(LPCTSTR btmapPath, Graphics* gfx) {
	this->gfx = gfx;
	sprites = new SpriteSheet(btmapPath, gfx, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void ContentInfo::Render() {
	sprites->Draw();
}