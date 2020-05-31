#include "Block.h"




Block::Block(LPCWSTR bitmapPath, Graphics *gfx, char symbol, 
				bool collisionEnabled, int index, int maxGeneratingHeight, int seed) {
	this->symbol = symbol;
	this->collisionEnabled = collisionEnabled;
	this->gfx = gfx;
	this->index = index;
	this->maxGeneratingHeight = maxGeneratingHeight;
	this->seed = seed;
	sprites = new SpriteSheet(bitmapPath, gfx, spriteWidth, spriteHeight);
}

Block::~Block() {
	delete sprites;
}



void Block::Render(int x, int y, int offset){
	sprites->Draw(index, static_cast<float>(x * spriteWidth - offset) , static_cast<float>(y * spriteHeight));
}



int Block::GetSeed() {
	return seed;
}
int Block::GetMaxGenerationHeight() {
	return maxGeneratingHeight;
}
int Block::GetIndex() {
	return index;
}
char Block::GetSymbol() {
	return symbol;
}
bool Block::IsCollisionEnabled() {
	return collisionEnabled;
}





