#pragma once
#include <vector>
#include "framework.h"
#include "SpriteSheet.h"
using namespace std;


class Block {

public:

	friend Block* GetBlockBySymbol(char symbol);
	friend Block* GetBlockByIndex(int index);
	friend Block* GetBlockByCoords(UINT16 x, UINT16 y);

	Block(LPCWSTR, Graphics*, char, bool, int, int = 0, int = 50);
	~Block();

	void Render(int x, int y, int offset);

	int GetSeed();
	int GetMaxGenerationHeight();
	int GetIndex();
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
		gold = 6,
	};


private:

	bool collisionEnabled;
	char symbol;
	int maxGeneratingHeight;
	int seed;
	int index;
	SpriteSheet* sprites;

	static const inline int spriteWidth = 32;
	static const inline int spriteHeight = 32;

};