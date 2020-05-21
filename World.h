/*
	2D Random Game World Generator with DirectX2D

	The program first randomly fills out the string vector
	Each character is each block symbol. For example for air is '_' and for diamond is '&'.

	Then it reads this vector and draws bitmaps assigned to each block on given coordinates.


	To create new block, add it to blockType vector in World::Init() function
	and add generating conditions to TerrainGenerator() Functions
	You can also add block index name into enum it Block.h 


	World.h
	Created on: 11.04.2020
	Author: Norbert Bielak

*/ 
#pragma once

#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <fstream>
#include <thread>

#include "framework.h"
#include "Block.h"
#include "Graphics.h"
#include "Utils.h"
#include "Chunks/Chunk.h"
#include "Animation/Animation.h"	
using namespace std;

class World{
public:
	friend Block* GetBlockBySymbol(char symbol);
	friend Block* GetBlockByIndex(int index);
	friend Block* GetBlockByCoords(UINT16 objPosX, UINT16 objPosY);
	friend Chunk* GetChunkByStartPoint(UINT16 startPoint);


	static void Init(Graphics *gfx);
	static void Unload();
	static void Render();
	static void Update();


	static UINT16 GetActualFloorLevel(UINT16 x);
	
	static int FindNearestLandY(int objPosX, int objPosY);
	static bool FindNearestWall(int& objPosX, int objPosY);
	
	static Chunk* actualChunk;
	static inline int offset = 0;
	static list<Chunk*> chunks;

private:



	static vector<int> randomStructArray;
	static thread* thr;
	static inline bool AddChunkFlag = false;
	static inline bool DeleteChunkFlag = false;


	static inline UINT16 blocksCountX = SCREEN_WIDTH/32;	
	static inline UINT16 blocksCountY = SCREEN_HEIGHT/32;
	static inline UINT16 averageFloorLevel = blocksCountY / 2;
	static inline UINT16 skyLevel = blocksCountY / 5;

	static void thrHandler();
	static void GenerateNewChunk();
	static void DeleteFirstChunk();

};