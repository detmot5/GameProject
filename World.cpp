#include "World.h"
using namespace Utils;


vector<Chunk*> World::chunks;
Chunk* World::actualChunk;







UINT16 World::GetActualFloorLevel(UINT16 x) {
	return actualChunk->GetActualFloorLevel(x);
}

UINT16 World::FindNearestLand(UINT16 objPosX, UINT16 objPosY) {
	for (UINT8 i = objPosY / 32; i < blocksCountY; i++) {
		if (actualChunk->isCollisionEnabled(*actualChunk ,objPosX / 32, i)) return i * 32;
	}
	return averageFloorLevel;
}




void World::Init(Graphics* gfx) {
	Chunk::Init(gfx);
	chunks.push_back(new Chunk(0));
	chunks.push_back(new Chunk(25));
	actualChunk = chunks[0];
}


void World::Update() {
	for (auto i : chunks) i->SetOffset(offset);
}

void World::Render() {
	for (auto i : chunks) i->Render();
}




