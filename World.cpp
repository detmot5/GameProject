#include "World.h"

using namespace Utils;

<<<<<<< HEAD
list<Chunk*> World::chunks;
Chunk* World::actualChunk;
thread* World::ChunkGenerateThread;



=======

list<Chunk*> World::chunks;
Chunk* World::actualChunk;
thread* World::ChunkGenerateThread;



>>>>>>> menu
Chunk* GetChunkByStartPoint(UINT16 startPoint) {
	for (auto i : World::chunks) {
		if (i->GetStartPoint() == startPoint) return i;
	}
	return nullptr;
<<<<<<< HEAD
}


bool World::isCollisionEnabled(UINT16 x, UINT16 y) {
	if (x >= GetNextChunkStartPoint()) return GetNextChunk()->isCollisionEnabled(x, y);
	else if (x < GetActualChunkStartPoint()) return GetPreviousChunk()->isCollisionEnabled(x, y);
	else return actualChunk->isCollisionEnabled(x, y);
=======
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
>>>>>>> menu
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

Chunk* World::GetNextChunk(){
	 return GetChunkByStartPoint(GetNextChunkStartPoint()); 
}
Chunk* World::GetPreviousChunk() {
	return GetChunkByStartPoint(GetPreviousChunkStartPoint());
}


void World::Init(Graphics* gfx, wstring Path) {
	Chunk::Init(gfx);
	GameSaver::InitSave(Path);
	chunks.push_back(new Chunk(0));
	chunks.push_back(new Chunk(25));
	chunks.push_back(new Chunk(50));

<<<<<<< HEAD
	for (auto i : chunks) {
		GameSaver::Write::SaveChunk(i);
	}
=======
void World::Init(Graphics* gfx) {
	Chunk::Init(gfx);
	chunks.push_back(new Chunk(0));
	chunks.push_back(new Chunk(25));
	chunks.push_back(new Chunk(50));
>>>>>>> menu
	actualChunk = chunks.front();

	ChunkGenerateThread = new thread(ChunkGenerateHandler);

}


void World::Load(Graphics* gfx, wstring Path) {
		// if reading error then generate new save
	Chunk::Init(gfx);
<<<<<<< HEAD
	if (GameSaver::Read::LoadSave(Path)) {
#if DEBUG_MODE && GAME_SAVER_DEBUG
		cout << "Save Loaded"<< endl;  
#endif
	}
=======
	if(GameSaver::Read::LoadSave(Path))
		cout << "Wczytano"<< endl;  
>>>>>>> menu

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
<<<<<<< HEAD
	delete ChunkGenerateThread;
	actualChunk = nullptr;
	ChunkGenerateThread = nullptr;
=======
>>>>>>> menu
}


void World::Update() {

<<<<<<< HEAD
	


	for (auto i : chunks) i->SetOffset(offset);


	if (GetActualPosition() + 13 >= GetNextChunkStartPoint()) {
		actualChunk = GetChunkByStartPoint(GetNextChunkStartPoint());
	}
	else if (GetActualPosition() + 13 < GetActualChunkStartPoint()) {
		actualChunk = GetChunkByStartPoint(GetPreviousChunkStartPoint());
	}

	if (GenerateBackDeleteFrontChunkFlag()){
		AddChunkOnBackFlag = true;
		if ((GetActualPosition() - GetFirstChunkStartPoint()) >= 100) DeleteFirstChunk();
	}

	else if (GenerateFrontDeleteBackChunkFlag()){
		AddChunkOnFrontFlag = true;
		if (GetLastChunkStartPoint() - GetActualPosition() >= 100) DeleteLastChunk();
	}
=======
	int actualPosition = offset / DEFAULT_BLOCK_SIZE;

	for (auto i : chunks) i->SetOffset(offset);


	if (actualPosition > GetNextChunkStartPoint()) {
		actualChunk = GetChunkByStartPoint(GetNextChunkStartPoint());
	}
	else if (actualPosition < GetActualChunkStartPoint()) {
		actualChunk = GetChunkByStartPoint(GetPreviousChunkStartPoint());
	}

	if (actualPosition >= GetActualChunkStartPoint() &&
		!GetChunkByStartPoint(GetNextChunkStartPoint() + Chunk::blocksCountX) &&
		!AddChunkFlag) {

		AddChunkFlag = true;

		if ((actualPosition - chunks.front()->GetStartPoint()) >= 100 ){
			DeleteFirstChunk();
		}
		
>>>>>>> menu

	}

<<<<<<< HEAD
#if DEBUG_MODE && GAME_GENERATOR_DEBUG
	cout << "                                            \r"
		<< convertToBlockCoord(static_cast<float>(offset)) << " "
		<< offset << " "
		<< actualChunk->GetStartPoint() << " "
		<< chunks.back()->GetStartPoint() << " "
		<< chunks.front()->GetStartPoint() << " "
		<< chunks.size();
		 
#endif

}

void World::Render() {
	for (auto i : chunks) i->Render();
	

=======

#if DEBUG_MODE
	cout <<"                                  \r" 
		 << offset/32 << " " 
		 << offset << " "
		 << actualChunk->GetStartPoint() << " " 
		 << chunks.back()->GetStartPoint();
#endif

>>>>>>> menu
}

void World::Render() {
	for (auto i : chunks) i->Render();
	

<<<<<<< HEAD
//----------------------------------------------------------------------------------------
//								PRIVATE FUNCTIONS
//----------------------------------------------------------------------------------------
void World::GenerateNewChunk() {
	chunks.push_back(new Chunk(chunks.back()->GetStartPoint() + Chunk::blocksCountX));
	if (!GameSaver::Write::SaveChunk(chunks.back())) {
#if DEBUG_MODE && GAME_SAVER_DEBUG
		cout << "Error Writing to file!" << endl;
#endif
	}

#if DEBUG_MODE && GAME_GENERATOR_DEBUG
	cout <<endl<< "Generated" << endl;
	cout << (offset / Chunk::blocksCountX) << endl;
	cout << chunks.back()->GetStartPoint()<<endl;
#endif
}


void World::DeleteFirstChunk() {
	chunks.pop_front();
#if DEBUG_MODE && GAME_GENERATOR_DEBUG
	cout << endl << "Deleted front" << endl;
#endif
}

void World::DeleteLastChunk() {
	chunks.pop_back();

#if DEBUG_MODE && GAME_GENERATOR_DEBUG
	cout << "Deleted back" << endl;
#endif
}

//----------------------------------------------------------------------------------------
//									CONDITIONS
//----------------------------------------------------------------------------------------

bool World::GenerateFrontDeleteBackChunkFlag() {
	if (GetActualPosition() <= GetActualChunkStartPoint() &&
		GetActualPosition() > 0 &&
		!GetChunkByStartPoint(GetPreviousChunkStartPoint()) &&  //Check if it is no chunk on the left
		!AddChunkOnFrontFlag
		) return true;

	return false;
}

bool World::GenerateBackDeleteFrontChunkFlag() {
	if (GetActualPosition() > GetActualChunkStartPoint() &&
		!GetChunkByStartPoint(GetNextChunkStartPoint() + Chunk::blocksCountX) &&
		!AddChunkOnBackFlag
		) return true;

	return false;
}

//-----------------------------------------------------------------------------------------


	//thread function
void World::ChunkGenerateHandler() { 
	
	while (true) {
		if (AddChunkOnBackFlag && GetActualChunkStartPoint() > 0) {
			if (chunks.back()->GetStartPoint() < GameSaver::Read::GetLastChunkStartPoint()) {
				chunks.push_back(GameSaver::Read::GetChunkFromBuffer(GetLastChunkStartPoint() + Chunk::blocksCountX));
#if DEBUG_MODE && GAME_GENERATOR_DEBUG
				cout << endl << "Loaded Back" << endl;
#endif
			}
			else {
				GenerateNewChunk();
			}
			AddChunkOnBackFlag = false;
		}
		else if (AddChunkOnFrontFlag && GetActualChunkStartPoint() > 0) {
			chunks.push_front(GameSaver::Read::GetChunkFromBuffer(GetFirstChunkStartPoint() - Chunk::blocksCountX));
#if DEBUG_MODE && GAME_GENERATOR_DEBUG
			cout << endl << "Loaded Front" << endl;
#endif
			AddChunkOnFrontFlag = false;
		}
	
=======
}


//----------------------------------------------------------------------------------------
//							   PRIVATE FUNCTIONS
//----------------------------------------------------------------------------------------
void World::GenerateNewChunk() {
	chunks.push_back(new Chunk(chunks.back()->GetStartPoint() + Chunk::blocksCountX));
	if (!GameSaver::Write::SaveChunk(chunks.back())) {
#if DEBUG_MODE
		cout << "Error Writing to file!" << endl;
#endif
	}

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

>>>>>>> menu
	}
}

