#include "Chunk.h"


vector<Block*> Chunk::BlockType;
vector<int> Chunk::randomStructArray;
Graphics* Chunk::gfx;


//---------------------------------------------------------------------------------------------------
//									GLOBAL FUNCTIONS
//---------------------------------------------------------------------------------------------------


Block* GetBlockBySymbol(char symbol) {
	for (UINT8 i = 0; i < Chunk::BlockType.size(); i++) {
		if (Chunk::BlockType[i]->symbol == symbol) {
			return Chunk::BlockType[i];
		}
	}
	return nullptr;

}

Block* GetBlockByIndex(int index) {
	for (UINT8 i = 0; i < Chunk::BlockType.size(); i++) {
		if (Chunk::BlockType[i]->index == index) {
			return Chunk::BlockType[i];
		}
	}
	return nullptr;
}

Block* Chunk::GetBlockByCoords(UINT16 x, UINT16 y) {
	return GetBlockBySymbol(this->chunkTemplate[y][x]);
}



void LoadBlock(string& target, int index) {
	target += GetBlockByIndex(index)->GetSymbol();
}


ostream& operator<<(ostream& os, Chunk* chunk) {
	os << chunk->StartPoint << endl;
	for (auto i : chunk->chunkTemplate) os << i << endl;
	os << endl;
	return os;
}

//UINT16 Chunk::FindNearestLand(UINT16 objPosX, UINT16 objPosY) {
//	for (UINT8 i = objPosY / 32; i < blocksCountY; i++) {
//		if (this->isCollisionEnabled(objPosX / 32, i)) return i * 32;
//	}
//	return averageFloorLevel;
//}


//---------------------------------------------------------------------------------------------------
//									STATIC FUNCTIONS
//---------------------------------------------------------------------------------------------------

void Chunk::Init(Graphics* gfx) {
	Chunk::gfx = gfx;

	BlockType.push_back(new Block(imgSrc, gfx, '_', false, Block::air));
	BlockType.push_back(new Block(imgSrc, gfx, '#', true, Block::stone, 0, 20));
	BlockType.push_back(new Block(imgSrc, gfx, '-', true, Block::grass));
	BlockType.push_back(new Block(imgSrc, gfx, '%', true , Block::dirt));
	BlockType.push_back(new Block(imgSrc, gfx, '*', false, Block::cave, 0, 10));
	BlockType.push_back(new Block(imgSrc, gfx, '&', true, Block::diamond, 2, 5));

	RandomArrayInit();
}



void Chunk::RandomArrayInit() {
	for (UINT8 i = 0; i < BlockType.size(); i++) {
		if (BlockType[i]->GetIndex() == Block::air) continue;
		if (BlockType[i]->GetIndex() == Block::grass) continue;
		for (UINT16 j = 0; j < BlockType[i]->GetSeed(); j++) {
			randomStructArray.push_back(BlockType[i]->GetIndex());
		}
	}
}

//---------------------------------------------------------------------------------------------------


Chunk::Chunk(UINT16 StartPoint){
	this->StartPoint = StartPoint;
	FloorLevelInit();
	this->ChunkTemplateInit();
}

Chunk::Chunk(UINT16 StartPoint, vector<string>& chunkTemplate){
	this->StartPoint = StartPoint;
	this->chunkTemplate = chunkTemplate;
}


Chunk::~Chunk(){

}

bool Chunk::isCollisionEnabled(UINT16 x, UINT16 y) {
	return GetBlockByCoords(x, y)->IsCollisionEnabled();
}

void Chunk::FloorLevelInit() {
	for (UINT16 i = 0; i <= blocksCountX; i++) {
		UINT16 actualFloorLevel = Utils::randint(averageFloorLevel, averageFloorLevel + 2);
		FloorLevel.insert(pair<UINT16, UINT16>(i, actualFloorLevel));
	}
}


UINT16 Chunk::GetActualFloorLevel(UINT16 x) {
	return FloorLevel.find(x)->second;
}



void Chunk::ChunkTemplateInit() {
	for (UINT8 i = 0; i < blocksCountY; i++) {
		chunkTemplate.push_back("");
		for (UINT8 j = 0; j < blocksCountX; j++) {
			TerrainGenerator(chunkTemplate[i], i, &j);
		}
	}
	FloorLevel.clear();
}


void Chunk::TerrainGenerator(string& target, int deepness, UINT8* iterator) {
	int pick = randomStructArray[Utils::randint(0, randomStructArray.size())];

	UINT16 actualFloorLevel = GetActualFloorLevel(*iterator);


	if (deepness == actualFloorLevel) {
		LoadBlock(target, Block::grass);
		return;
	}
	else if (deepness < actualFloorLevel) {
		LoadBlock(target, Block::air);
		return;
	}

	switch (pick) {

	case Block::diamond:
		if (deepness >= blocksCountY - 2)
			LoadBlock(target, Block::diamond);
		else
			LoadBlock(target, Block::stone);
		break;

	case Block::stone:
		LoadBlock(target, Block::stone);
		break;

	case Block::dirt:
		if (deepness > actualFloorLevel && deepness < actualFloorLevel + 2) {
			LoadBlock(target, Block::dirt);
		}

		else {
			LoadBlock(target, Block::stone);
		}
		break;

	case Block::cave:
		GenerateCave(target, 0, iterator);
		break;
	}
}

void Chunk::GenerateCave(string& target, int deepness, UINT8* iterator) {
	if (!iterator) return;
	for (UINT8 i = 0; i < Utils::randint(3, 8) && *iterator < blocksCountX; i++) {
		LoadBlock(target, Block::cave);
		(*iterator)++;
	}
	(*iterator)--;

}



void Chunk::Update() {
	
}



void Chunk::Render() {
	
	static bool isDisplayed = false;
#if DEBUG_MODE && GAME_GENERATOR_DEBUG
	if (!isDisplayed) {
		Utils::printVector(chunkTemplate,"\n");
		isDisplayed = true;
	}
#endif

	for (UINT8 i = 0; i < chunkTemplate.size(); i++) {
		for (UINT8 j = 0; j < chunkTemplate[i].length(); j++) {
			GetBlockBySymbol(chunkTemplate[i].at(j))->Render(static_cast<int>(j+StartPoint), i,offset);
		}
	}

}

