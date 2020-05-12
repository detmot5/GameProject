#include "World.h"
using namespace Utils;


list<Chunk*> World::chunks;
Chunk* World::actualChunk;







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

	actualChunk = chunks.front();
}


void World::Update() {
	UINT16 actualStartPoint;
	for (auto i : chunks) {
		actualStartPoint = chunks.back()->GetStartPoint();
		i->SetOffset(offset);
	}
	if (abs(offset / 25) >= actualStartPoint) {
		actualChunk = chunks.back();
		chunks.push_back(new Chunk(actualStartPoint + 25));
#if DEBUG_MODE 
		cout << "Generated" << endl; 
		cout << (offset/25)  << endl;
#endif
	}
	if (abs(offset / 25) - chunks.front()->GetStartPoint() > 200) {
		chunks.pop_front();
#if DEBUG_MODE
		cout << "Deleted" << endl;
#endif
	}
	cout << offset/25 << endl;

}

void World::Render() {
	for (auto i : chunks) i->Render();
}




