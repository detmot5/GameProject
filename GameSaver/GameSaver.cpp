#include "GameSaver.h"


namespace GameSaver {
	static list<Chunk*> ChunkBuffer;
	static vector<string> buffer;

	fstream fileStream;
<<<<<<< HEAD
	const wstring directoryPath = Path::savesDirectory;
	wstring saveName;


	static inline void ParsePath(const wstring& filePath) {
=======
	const wstring directoryPath = L"GameProject/Saves/";
	wstring saveName = L"mysave";


	static inline void ParsePath(wstring filePath) {
>>>>>>> menu
		saveName = directoryPath + filePath;
	}


<<<<<<< HEAD
	void InitSave(const wstring filePath) {
		if (!filesystem::exists(directoryPath))	filesystem::create_directory(directoryPath);
		ParsePath(filePath);

			// clear file
		fileStream.open(saveName, ios::out);
		fileStream.close();
	
=======
	void InitSave(wstring filePath) {
		if (!filesystem::exists(directoryPath))	filesystem::create_directory(directoryPath);
		ParsePath(filePath);
			//create empty file
		fileStream.open(saveName, ios::out);
		fileStream.close();
>>>>>>> menu
	}

	namespace Write {
		bool SaveChunk(Chunk* chunk) {
			fileStream.open(saveName, ios::app);
<<<<<<< HEAD
			if (fileStream.fail()) return false;
=======
			if (fileStream.fail()) return false;;
>>>>>>> menu
			ChunkBuffer.push_back(chunk);
			fileStream << ChunkBuffer.back();
			fileStream.close();

<<<<<<< HEAD
#if DEBUG_MODE && GAME_SAVER_DEBUG
			cout << endl << "Saved" << chunk->GetStartPoint() << endl;
=======
#if DEBUG_MODE
			cout << endl << "Zapisano " << chunk->GetStartPoint() << endl;
>>>>>>> menu
#endif
			return true;
		}


	}
	



	namespace Read {

<<<<<<< HEAD
		static bool ReadFile(const wstring path) {
			ParsePath(path);
			if (!filesystem::exists(saveName)) {
#if DEBUG_MODE && GAME_SAVER_DEBUG
				cout << "File doesn't exist!" << endl;
#endif
=======
		static bool ReadFile(wstring path) {
			if (!filesystem::exists(path)) {
				#if DEBUG_MODE
				cout << "File doesn't exist!" << endl;
				#endif
>>>>>>> menu
				return false;
			}
			string temp;

<<<<<<< HEAD
			fileStream.open(saveName, ios::in);
=======
			fileStream.open(path, ios::in);
>>>>>>> menu
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
<<<<<<< HEAD
			ParsePath(path);
=======


>>>>>>> menu
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
<<<<<<< HEAD
=======
			cout << endl <<ChunkBuffer.front();
>>>>>>> menu
			return ChunkBuffer.back()->GetStartPoint();
		}


		



	}




}