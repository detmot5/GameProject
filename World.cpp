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

//void World::FindNearestLand(int objPosX, int& objPosY) {
//
//	int test_var_x = objPosX / 32;
//
//	int test_var_y = objPosY / 32;
//
//	if (test_var_y >= 20)
//	{
//		objPosY = averageFloorLevel;
//	}
//	else if (actualChunk->isCollisionEnabled(test_var_x, test_var_y))
//	{
//		++test_var_y;
//
//		objPosY = test_var_y * 32;
//	}
//}

int World::FindNearestLandY(int objPosX, int objPosY)
{

	for (UINT16 i = objPosY / 32; i < blocksCountY; i++)
	{
		if (!actualChunk->isCollisionEnabled(round(objPosX / 32), i))
		{
			return i * 32;
		}
	}
	return averageFloorLevel;
}

bool World::FindNearestWall(int& objPosX, int objPosY)
{
	int test_var_x = objPosX;
	test_var_x /= 32;

	int test_var_y = (objPosY) / 32;

	if (actualChunk->isCollisionEnabled(test_var_x + 1, test_var_y - 1))
	{
		return true;
	}
	else
	{
		return false;
	}
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




