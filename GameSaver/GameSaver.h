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
	void InitSave(wstring saveName);
	namespace Write {
		void SaveChunk(Chunk* chunk);	
	}

	namespace Read {
		void LoadSave(wstring path);
		Chunk* GetChunkFromBuffer(UINT16 StartPoint);
	}

};