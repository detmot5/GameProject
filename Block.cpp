#include "Block.h"






Block::Block(LPCWSTR bitmapPath, Graphics *gfx, char symbol, 
				bool collisionEnabled, short index, short maxGeneratingHeight, short seed) {
	this->symbol = symbol;
	this->collisionEnabled = collisionEnabled;
	this->gfx = gfx;
	this->index = index;
	this->maxGeneratingHeight = maxGeneratingHeight;
	this->seed = seed;
	sprites = new SpriteSheet(bitmapPath, gfx, spriteWidth, spriteHeight);
}



void Block::Render(short x, short y){
	sprites->Draw(index, x*spriteWidth, y*spriteHeight);
}





short Block::GetSeed() {
	return seed;
}
short Block::GetMaxGenerationHeight() {
	return maxGeneratingHeight;
}
short Block::GetIndex() {
	return index;
}
char Block::GetSymbol() {
	return symbol;
}
bool Block::IsCollisionEnabled() {
	return collisionEnabled;
}





