#include "World.h"

using namespace Utils;


list<Chunk*> World::chunks;
Chunk* World::actualChunk;
thread* World::ChunkGenerateThread;



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
		if (!actualChunk->isCollisionEnabled(objPosX / 32, i))
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

	ChunkGenerateThread = new thread(ChunkGenerateHandler);

}


void World::Load(Graphics* gfx) {
	Chunk::Init(gfx);
	GameSaver::Read::LoadSave(L"GameProject/Saves/myBigWorld.sav");

	chunks.push_back(GameSaver::Read::GetChunkFromBuffer(0));
	chunks.push_back(GameSaver::Read::GetChunkFromBuffer(25));
	chunks.push_back(GameSaver::Read::GetChunkFromBuffer(50));

	actualChunk = chunks.front();

	ChunkGenerateThread = new thread(ChunkGenerateHandler);
	
}


void World::Unload() {
	ChunkGenerateThread->detach();
	chunks.clear();
	delete actualChunk;
}


void World::Update() {

	int actualPosition = offset / DEFAULT_BLOCK_SIZE;

	for (auto i : chunks) i->SetOffset(offset);


	if (actualPosition > GetNextChunkStartPoint()) {
		actualChunk = GetChunkByStartPoint(GetNextChunkStartPoint());
	}
	else if (actualPosition < GetActualChunkStartPoint()) {
		actualChunk = GetChunkByStartPoint(GetPreviousChunkStartPoint());
		//chunks.push_front(GameSaver::Read::GetChunkFromBuffer(chunks.front()->GetStartPoint() - Chunk::blocksCountX));
	}

	if (actualPosition >= GetActualChunkStartPoint() &&
		!GetChunkByStartPoint(GetNextChunkStartPoint() + Chunk::blocksCountX) &&
		!AddChunkFlag) {

		AddChunkFlag = true;

		if ((actualPosition - chunks.front()->GetStartPoint()) >= 100 ){
			DeleteFirstChunk();
		}
		

	}


#if DEBUG_MODE
	cout <<"                                  \r" 
		 << offset/32 << " " 
		 << offset << " "
		 << actualChunk->GetStartPoint() << " " 
		 << chunks.back()->GetStartPoint();
#endif

}

void World::Render() {
	for (auto i : chunks) i->Render();
	

}


//----------------------------------------------------------------------------------------
//							   PRIVATE FUNCTIONS
//----------------------------------------------------------------------------------------
void World::GenerateNewChunk() {
	chunks.push_back(new Chunk(chunks.back()->GetStartPoint() + Chunk::blocksCountX));
	GameSaver::Write::SaveChunk(chunks.back());
#if DEBUG_MODE 
	cout <<endl<< "Generated" << endl;
	cout << (offset / Chunk::blocksCountX) << endl;
	cout << chunks.back()->GetStartPoint()<<endl;
#endif
}


void World::DeleteFirstChunk() {
	
	


	delete chunks.front();
	chunks.pop_front();
#if DEBUG_MODE
	cout << "Deleted" << endl;
#endif
}




void World::ChunkGenerateHandler() {
	
	while (true) {
		if (AddChunkFlag) {

			if (chunks.back()->GetStartPoint() < GameSaver::Read::GetLastChunkStartPoint()) {
				chunks.push_back(GameSaver::Read::GetChunkFromBuffer(chunks.back()->GetStartPoint() + Chunk::blocksCountX));
#if DEBUG_MODE
				cout << "Loaded" << endl;
#endif
			}
			else {
				GenerateNewChunk();
			}
			AddChunkFlag = false;
		}

	}
}

