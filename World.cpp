#include "World.h"
using namespace Utils;


list<Chunk*> World::chunks;
Chunk* World::actualChunk;




Chunk* GetChunkByStartPoint(UINT16 startPoint) {
	for (auto i : World::chunks) {
		if (i->GetStartPoint() == startPoint) return i;
	}
	return nullptr;
}


UINT16 World::GetActualFloorLevel(UINT16 x) {
	return actualChunk->GetActualFloorLevel(x);
}

UINT16 World::FindNearestLand(UINT16 objPosX, UINT16 objPosY) {
	for (UINT8 i = objPosY / 32; i < blocksCountY; i++) {
		if (actualChunk->isCollisionEnabled(objPosX / 32, i)) return i * 32;
	}
	return averageFloorLevel;
}




void World::Init(Graphics* gfx) {
	Chunk::Init(gfx);
	chunks.push_back(new Chunk(0));
	chunks.push_back(new Chunk(25));
	chunks.push_back(new Chunk(50));

	actualChunk = chunks.front();
}

void World::Unload() {
	chunks.clear();
	delete actualChunk;
}


void World::Update() {
	UINT16 actualStartPoint;
	UINT16 nextChunkStartPoint;

	for (auto i : chunks) i->SetOffset(offset);

	
	if ((int)abs(offset / Chunk::blocksCountX) >= actualChunk->GetStartPoint() && !GetChunkByStartPoint(actualChunk->GetStartPoint()+25)) {
		chunks.push_back(new Chunk(chunks.back()->GetStartPoint() + Chunk::blocksCountX));
#if DEBUG_MODE 
		cout << "Generated" << endl; 
		cout << (offset/ Chunk::blocksCountX)  << endl;
#endif
	}

	nextChunkStartPoint =  actualChunk->GetStartPoint();


	if (abs(offset) / 25 > actualChunk->GetStartPoint() + 25) {
		actualChunk = GetChunkByStartPoint(actualChunk->GetStartPoint() + 25);
	}
	else if (abs(offset) / 25 < actualChunk->GetStartPoint())  {
		actualChunk = GetChunkByStartPoint(actualChunk->GetStartPoint() - 25);
	}
	
	cout <<"              \r" << offset/25 << " " << actualChunk->GetStartPoint() << " " << chunks.back()->GetStartPoint();


}

void World::Render() {
	for (auto i : chunks) i->Render();
}




