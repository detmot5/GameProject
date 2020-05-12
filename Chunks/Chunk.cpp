#include "Chunk.h"


vector<Block*> Chunk::BlockType;
vector<short> Chunk::randomStructArray;
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

Block* GetBlockByIndex(short index) {
	for (UINT8 i = 0; i < Chunk::BlockType.size(); i++) {
		if (Chunk::BlockType[i]->index == index) {
			return Chunk::BlockType[i];
		}
	}
	return nullptr;
}

Block* GetBlockByCoords(Chunk& chunk, UINT16 x, UINT16 y) {
	return GetBlockBySymbol(chunk.chunkTemplate[y][x]);
}

bool Chunk::isCollisionEnabled(UINT16 x, UINT16 y) {
	return GetBlockByCoords(*this,x, y)->IsCollisionEnabled();
}


void LoadBlock(string& target, short index) {
	target += GetBlockByIndex(index)->GetSymbol();
}



UINT16 Chunk::FindNearestLand(UINT16 objPosX, UINT16 objPosY) {
	for (UINT8 i = objPosY / 32; i < blocksCountY; i++) {
		if (this->isCollisionEnabled(objPosX / 32, i)) return i * 32;
	}
	return averageFloorLevel;
}


//---------------------------------------------------------------------------------------------------
//									STATIC FUNCTIONS
//---------------------------------------------------------------------------------------------------

void Chunk::Init(Graphics* gfx) {
	Chunk::gfx = gfx;

	BlockType.push_back(new Block(imgSrc, gfx, '_', false, Block::air));
	BlockType.push_back(new Block(imgSrc, gfx, '#', true, Block::stone, 0, 20));
	BlockType.push_back(new Block(imgSrc, gfx, '-', true, Block::grass));
	BlockType.push_back(new Block(imgSrc, gfx, '%', true, Block::dirt));
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
	cout << "Start" << endl;
	this->StartPoint = StartPoint;
	this->FloorLevelInit();
	this->ChunkTemplateInit();
	Utils::printVector(chunkTemplate,"\n");
}

Chunk::~Chunk(){

}


void Chunk::FloorLevelInit() {
	for (UINT16 i = 0; i <= blocksCountX; i++) {
		UINT16 actualFloorLevel = Utils::randint(averageFloorLevel, averageFloorLevel + 2);
		FloorLevel.insert(pair<UINT16, UINT16>(i, actualFloorLevel));
	}
}



UINT16 Chunk::GetActualFloorLevel(UINT16 x) {
	UINT16 a = 0;
	try{
	
		auto result = FloorLevel.find(x);
		a = result->second;
	}
	catch (const std::invalid_argument& ia) {
		cout << a << endl;
	}
	return a;
}



void Chunk::ChunkTemplateInit() {
	for (UINT8 i = 0; i < blocksCountY; i++) {
		chunkTemplate.push_back("");
		for (UINT8 j = 0; j < blocksCountX; j++) {
			TerrainGenerator(chunkTemplate[i], i, &j);
		}
	}
}


void Chunk::TerrainGenerator(string& target, short deepness, UINT8* iterator) {
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

void Chunk::GenerateCave(string& target, short deepness, UINT8* iterator) {
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
#if DEBUG_MODE
	if (!isDisplayed) {
		Utils::printVector(chunkTemplate,"\n");
		isDisplayed = true;
	}
#endif

	for (UINT8 i = 0; i < chunkTemplate.size(); i++) {
		for (UINT8 j = 0; j < chunkTemplate[i].length(); j++) {
			GetBlockBySymbol(chunkTemplate[i].at(j))->Render(static_cast<float>(j+StartPoint), i,offset);
		}
	}

}

