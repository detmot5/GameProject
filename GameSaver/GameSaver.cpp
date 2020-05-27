#include "GameSaver.h"


namespace GameSaver {
	static list<Chunk*> ChunkBuffer;
	static vector<string> buffer;

	fstream fileStream;
	const wstring directoryName = L"GameProject\\Saves";
	wstring fileName = L"mysave";


	void InitSave(wstring saveName) {
		if (!filesystem::exists(directoryName))	filesystem::create_directory(directoryName);
		
		fileName = saveName + L".sav";
		fileStream.open(directoryName + L"\\" + fileName, ios::out);
		fileStream.close();
	}

	namespace Write {
		void SaveChunk(Chunk* chunk) {
		
			fileStream.open(directoryName + L"\\" + fileName, ios::app);
			ChunkBuffer.push_back(chunk);
			fileStream << chunk;
			fileStream.close();
		}
	}




	namespace Read {

		static void ReadFile(wstring path) {
			if (!filesystem::exists(path)) {
				#if DEBUG_MODE
				cout << "File doesn't exist!" << endl;
				#endif
				return;
			}
			string temp;

			fileStream.open(path, ios::in);

			while (!fileStream.eof()) {
				fileStream >> temp;
				temp.erase(remove(temp.begin(), temp.end(), '\n'), temp.end());
				buffer.push_back(temp);
				temp.clear();
			}
			fileStream.close();
		}


		static Chunk* ReadChunksFromFileBuffer(UINT16 StartPoint) {
			stringstream sstr;
			sstr << StartPoint;
			string startPointStr = sstr.str();
			vector<string> temp;

			for (int i = 0; i < buffer.size(); i++) {
				if (buffer[i] == startPointStr) {
					for (int j = i; j <= i + Chunk::blocksCountY; j++) {
						temp.push_back(buffer[j]);
					}
					return new Chunk(StartPoint, temp);
				}
			}
			return nullptr;
		}




		void LoadSave(wstring path) {
			ReadFile(path);
			int startPoint = 0;
			Chunk* ChunkToSave;

			do {
				ChunkToSave = ReadChunksFromFileBuffer(startPoint);
				ChunkBuffer.push_back(ChunkToSave);
				startPoint += Chunk::blocksCountX;
			} while (nullptr != ChunkToSave);
		
		}


		Chunk* GetChunkFromBuffer(UINT16 StartPoint) {
			for (auto chunk : ChunkBuffer) {
				if (StartPoint == chunk->GetStartPoint()) {
					return chunk;
				}
			}
			return nullptr;
		}

	}




}