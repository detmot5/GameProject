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
#include <thread>

#include "framework.h"
#include "Block.h"
#include "Graphics.h"
#include "Utils.h"
#include "Chunks/Chunk.h"
#include "GameSaver/GameSaver.h"
#include "Animation/Animation.h"	

using namespace std;

class World{
public:
	friend Block* GetBlockBySymbol(char symbol);
	friend Block* GetBlockByIndex(int index);
	friend Chunk* GetChunkByStartPoint(UINT16 startPoint);


	static void Init(Graphics* gfx, wstring Path);
	static void Load(Graphics* gfx, wstring Path);
	static void Unload();
	static void Render();
	static void Update();


	
	
	static bool isCollisionEnabled(UINT16 x, UINT16 y);
	
	static inline int offset = 0;
	static Chunk* actualChunk;
	static list<Chunk*> chunks;

private:



	static vector<int> randomStructArray;
	static thread* ChunkGenerateThread;
	static inline bool AddChunkOnBackFlag = false;
	static inline bool AddChunkOnFrontFlag = false;

	static inline UINT16 blocksCountX = SCREEN_WIDTH / DEFAULT_BLOCK_SIZE;	
	static inline UINT16 blocksCountY = SCREEN_HEIGHT / DEFAULT_BLOCK_SIZE;
	static inline UINT16 averageFloorLevel = blocksCountY / 2;
	static inline UINT16 skyLevel = blocksCountY / 5;
	

	static inline int GetActualPosition() { return  offset / DEFAULT_BLOCK_SIZE; }

	
	static Chunk* GetNextChunk();
	static Chunk* GetPreviousChunk();
	static inline UINT16 GetActualChunkStartPoint() { return actualChunk->GetStartPoint(); }
	static inline UINT16 GetNextChunkStartPoint() { return GetActualChunkStartPoint() + Chunk::blocksCountX; }
	static inline UINT16 GetPreviousChunkStartPoint() { return GetActualChunkStartPoint() - Chunk::blocksCountX; };
	static inline UINT16 GetLastChunkStartPoint() { return chunks.back()->GetStartPoint(); }
	static inline UINT16 GetFirstChunkStartPoint() { return chunks.front()->GetStartPoint(); }

	static bool GenerateBackDeleteFrontChunkFlag();
	static bool GenerateFrontDeleteBackChunkFlag();

	static void ChunkGenerateHandler();
	static void GenerateNewChunk();
	static void DeleteFirstChunk();
	static void DeleteLastChunk();

};