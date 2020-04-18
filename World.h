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
<<<<<<< HEAD
	static inline const LPCWSTR imgSrc = L"C:/mySoft/GameProject/Workspace/GameProject/source/Graphicss/block.png";
=======
	static inline const LPCWSTR imgSrc = L"../GameProject/Graphicss/block.png";
>>>>>>> added character

private:

	static vector<short> randomArray;
	static vector<string> worldTemplate;


	static inline UINT16 blocksCountX = SCREEN_WIDTH/32;	
	static inline UINT16 blocksCountY = SCREEN_HEIGHT/32;
	static inline UINT16 floorLevel = blocksCountY / 2;
	static inline UINT16 skyLevel = blocksCountY / 5;

	static void (*RandomStructGenerator[])(string&, short, UINT8*);



	static void randomArrayInitialize();
	static void worldTemplateInitialize();

	static void airGenerator(string& target, short deepness, UINT8* iterator);
	static void terrainGenerator(string& target, short deepness, UINT8* iterator);
	static void caveGenerator(string& target, short deepness, UINT8* iterator);


};