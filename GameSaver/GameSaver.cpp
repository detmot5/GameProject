
#include "GameSaver.h"


namespace GameSaver {
	static list<Chunk*> ChunkBuffer;
	static vector<string> buffer;
	


	fstream fileStream;
	const wstring directoryPath = Path::savesDirectory;
	wstring saveName;


	static inline void ParsePath(const wstring& filePath) {
		saveName = directoryPath + filePath;
	}



	wstring GenerateSaveName() {
		static int savesCnt = 1;
		for (const auto& entry : filesystem::directory_iterator(directoryPath))	savesCnt++;
		wstringstream sstr;
		sstr << savesCnt+1;

		wstring name = L"save" + sstr.str();
		name += L".sav";
		return name;
	}

	vector<wstring> GetAllSaves() {
		vector<wstring> files;
		for (const auto& entry : filesystem::directory_iterator(directoryPath)) {
			files.push_back(entry.path().filename().wstring());
		}
		return files;
	}




	void InitSave() {
		if (!filesystem::exists(directoryPath))	filesystem::create_directory(directoryPath);
		wstring name = GenerateSaveName();
		buffer.clear();
		ChunkBuffer.clear();
		saveName.clear();
		ParsePath(name);

		// clear file
		fileStream.open(saveName, ios::out);
		fileStream.close();
	}

	namespace Write {
		bool SaveChunk(Chunk* chunk) {
			fileStream.open(saveName, ios::app);
			if (fileStream.fail()) return false;
			ChunkBuffer.push_back(chunk);
			fileStream << ChunkBuffer.back();
			cout << ChunkBuffer.back();
			fileStream.close();

#if DEBUG_MODE && GAME_SAVER_DEBUG
			cout << endl << "Saved" << chunk->GetStartPoint() << endl;
#endif
			return true;
		}


	}




	namespace Read {

		static bool ReadFile(const wstring path) {
			if (!filesystem::exists(saveName)) {
#if DEBUG_MODE && GAME_SAVER_DEBUG
				cout << "File doesn't exist!" << endl;
#endif
				return false;
			}
			string temp;

			fileStream.open(saveName, ios::in);
			if (fileStream.fail()) return false;

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
					for (int j = i + 1; j <= i + Chunk::blocksCountY; j++) {
						temp.push_back(buffer[j]);
					}
					return new Chunk(StartPoint, temp);
				}
			}

			cout << endl;
			return nullptr;
		}




		bool LoadSave(wstring path) {
			ChunkBuffer.clear();
			buffer.clear();
			saveName.clear();
			ParsePath(path);

			if (!ReadFile(path)) return false;
			int startPoint = 0;
			Chunk* ChunkToSave = ReadChunksFromFileBuffer(startPoint);;


			while (nullptr != ChunkToSave) {
				ChunkBuffer.push_back(ChunkToSave);
				startPoint += Chunk::blocksCountX;
				ChunkToSave = ReadChunksFromFileBuffer(startPoint);
			}

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
			return ChunkBuffer.back()->GetStartPoint();
		}






	}




}