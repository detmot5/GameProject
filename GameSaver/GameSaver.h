#pragma once
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include <list>
#include <algorithm>
#include "../framework.h"
#include "../Chunks/Chunk.h"
using namespace std;

namespace GameSaver {
	void InitSave();
	vector<wstring> GetAllSaves();
	namespace Write {
		bool SaveChunk(Chunk* chunk);	
	}

	namespace Read {
		bool LoadSave(wstring path);
		Chunk* GetChunkFromBuffer(UINT16 StartPoint);
		UINT16 GetLastChunkStartPoint();
	}

};