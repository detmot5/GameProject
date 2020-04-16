#pragma once

#include <vector>
#include <ctime>
#include "framework.h"
#include "Block.h"
#include "Graphics.h"
using namespace std;

class World {
public:
	friend Block* GetBlockBySymbol(char symbol);
	friend Block* GetBlockByIndex(short index);

	static void Init(Graphics *gfx);
	static void Render();
	static void Update();
	static vector<Block*> blockType;


private:

	static vector<short> randomArray;
	static vector<string> worldTemplate;




	static inline unsigned short blocksCountX = SCREEN_WIDTH/32 - 1 ;	
	static inline unsigned short blocksCountY = SCREEN_HEIGHT/32 - 1;
	static inline unsigned short floorLevel = blocksCountY / 2;

	static void (*RandomStructGenerator[])(string&, short, int*);



	static void randomArrayInitialize();
	static void worldTemplateInitialize();

	static void airGenerator(string& target, short deepness, int* iterator);
	static void terrainGenerator(string& target, short deepness, int* iterator);
	static void caveGenerator(string& target, short deepness, int* iterator);


};