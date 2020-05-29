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

			fileStream.open(L"GameProject/Saves/myBigWorld.sav", ios::app);
			if (fileStream.fail()) cout << "Error" << endl;
			ChunkBuffer.push_back(chunk);
			fileStream << ChunkBuffer.back();
			fileStream.close();
			cout << endl << "Zapisano " << chunk->GetStartPoint() << endl;
		}

		void SaveOnExit() {
			fileStream.open(L"GameProject/Saves/myBigWorld.sav", ios::out);
			for (auto chunk : ChunkBuffer) {
				fileStream << chunk;
			}
			fileStream.close();
		
		}

	}
	



	namespace Read {

		static bool ReadFile(wstring path) {
			if (!filesystem::exists(path)) {
				#if DEBUG_MODE
				cout << "File doesn't exist!" << endl;
				#endif
				return false;
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
			return true;
		}


		static Chunk* ReadChunksFromFileBuffer(UINT16 StartPoint) {
			stringstream sstr;
			sstr << StartPoint;
			string startPointStr = sstr.str();
			vector<string> temp;

			if (buffer.empty()) return nullptr;

			for (int i = 0; i < buffer.size(); i++) {
				if (buffer[i] == startPointStr) {
					for (int j = i + 1 ; j <= i + Chunk::blocksCountY; j++) {
						temp.push_back(buffer[j]);
					}
					return new Chunk(StartPoint, temp);
				}
			}

			cout << endl;
			return nullptr;
		}



		
		bool LoadSave(wstring path) {

			if (!ReadFile(path)) return false;
			

			int startPoint = 0;
			Chunk* ChunkToSave = ReadChunksFromFileBuffer(startPoint);;
			cout << "Ostatni: ";

			while (nullptr != ChunkToSave) {
				ChunkBuffer.push_back(ChunkToSave);
				startPoint += Chunk::blocksCountX;
				ChunkToSave = ReadChunksFromFileBuffer(startPoint);
			}
			cout << "xd" << endl;
			cout << ChunkBuffer.back()->GetStartPoint()<< endl;
			
			return true;
			
		}


		Chunk* GetChunkFromBuffer(UINT16 StartPoint) {
			for (auto chunk : ChunkBuffer) {
				if (StartPoint == chunk->GetStartPoint()) {
					return chunk;
				}
			}
			return nullptr;
		}

		UINT16 GetLastChunkStartPoint() {
			cout << endl <<ChunkBuffer.front();
			return ChunkBuffer.back()->GetStartPoint();
		}


		



	}




}