#pragma once
#include <vector>
#include "framework.h"
#include "SpriteSheet.h"
using namespace std;


class Block {

public:

	friend Block* GetBlockBySymbol(char symbol);
	friend Block* GetBlockByIndex(short index);
	friend Block* GetBlockByCoords(UINT16 x, UINT16 y);

	Block(LPCWSTR, Graphics*, char, bool, short, short = 0, short = 50);
	~Block();

	void Render(double x, double y, double offset);

	short GetSeed();
	short GetMaxGenerationHeight();
	short GetIndex();
	char  GetSymbol();
	bool  IsCollisionEnabled();
	Graphics* gfx;
	

	enum blockIndexes {
		stone = 0,
		cave = 1,
		air = 2,
		grass = 3,
		dirt = 4,
		diamond = 5,
	};


private:

	bool collisionEnabled;
	char symbol;
	short maxGeneratingHeight;
	short seed;
	short index;
	SpriteSheet* sprites;

	static const inline short spriteWidth = 32;
	static const inline short spriteHeight = 32;

};