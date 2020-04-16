#pragma once
#include <vector>
#include "framework.h"
#include "SpriteSheet.h"
using namespace std;

class Block {

public:
	friend Block* GetBlockBySymbol(char symbol);
	friend Block* GetBlockByIndex(short index);
	Block(LPCWSTR, Graphics*, char, bool, short, short = 50);
	void Render(short x, short y);

	short GetSeed();
	short GetMaxGenerationHeight();
	char GetSymbol();
	bool IsCollisionEnabled();
	

	Graphics* gfx;
	enum blockIndexes {
		air = 0,
		stone = 1,
		grass = 2,
		dirt = 3,
	};


private:

	bool collisionEnabled;
	char symbol;
	short maxGeneratingHeight;
	short seed;
	short index;
	


	SpriteSheet* sprites;

	static const inline  short spriteWidth = 32;
	static const inline  short spriteHeight = 32;

};