#pragma once
#include <vector>
#include <map>
#include <thread>
#include "../framework.h"
#include "../Block.h"
#include "../SpriteSheet.h"
#include "../Graphics.h"
#include "../Utils.h"

using namespace std;


class Chunk {
public:
	Chunk(UINT16 StartPoint);
	Chunk(UINT16 StartPoint, vector<string> chunkTemplate);
	~Chunk();
	static void Init(Graphics* gfx);		//call it before making object
	UINT16 GetActualFloorLevel(UINT16 x);
	/*UINT16 FindNearestLand(UINT16 objPosX, UINT16 objPosY);*/
	bool isCollisionEnabled(UINT16 x, UINT16 y);

	void Update();
	void Render();
	

	inline void SetOffset(int offset) { this->offset = offset; }
	inline int GetOffset() { return this->offset; }
	inline UINT16 GetStartPoint() { return this->StartPoint; }
	static const inline UINT16 blocksCountX = SCREEN_WIDTH / 32;
	static const inline UINT16 blocksCountY = SCREEN_HEIGHT / 32;
private:

	static const inline  LPCWSTR imgSrc = L"GameProject/Graphicss/block.png";
	static inline UINT16 averageFloorLevel = blocksCountY / 2;
	static inline UINT16 skyLevel = blocksCountY / 5;
	static vector<Block*> BlockType;
	static vector<int> randomStructArray;
	static Graphics* gfx;

	static void RandomArrayInit();

	vector<string> chunkTemplate;
	map<UINT16, UINT16> FloorLevel;
	UINT16 StartPoint;
	int offset;
	


	void ChunkTemplateInit();
	void FloorLevelInit();
	void TerrainGenerator(string& target, int deepness, UINT8* iterator);
	void GenerateCave(string& target, int deepness, UINT8* iterator);

	friend Block* GetBlockBySymbol(char symbol);
	friend Block* GetBlockByIndex(int index);
	friend Block* GetBlockByCoords(Chunk& chunk, UINT16 x, UINT16 y);
	friend ostream& operator<<(ostream& os, Chunk* chunk);
};
Block* GetBlockBySymbol(char symbol);