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


bool World::isCollisionEnabled(UINT16 x, UINT16 y) {
	if (x >= GetNextChunkStartPoint()) return GetNextChunk()->isCollisionEnabled(x, y);
	else if (x < GetActualChunkStartPoint()) return GetPreviousChunk()->isCollisionEnabled(x, y);
	else return actualChunk->isCollisionEnabled(x, y);
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

	for (auto i : chunks) {
		GameSaver::Write::SaveChunk(i);
	}
	actualChunk = chunks.front();

	ChunkGenerateThread = new thread(ChunkGenerateHandler);

}


void World::Load(Graphics* gfx, wstring Path) {
		// if reading error then generate new save
	Chunk::Init(gfx);
	if (GameSaver::Read::LoadSave(Path)) {
#if DEBUG_MODE && GAME_SAVER_DEBUG
		cout << "Save Loaded"<< endl;  
#endif
	}

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
	delete ChunkGenerateThread;
	actualChunk = nullptr;
	ChunkGenerateThread = nullptr;
}


void World::Update() {

	


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
	

}


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
	cout << "Deleted front" << endl;
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
	
	}
}

