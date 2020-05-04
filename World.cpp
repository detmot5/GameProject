#include "World.h"
using namespace Utils;

vector<string> World::worldTemplate;
vector<Block*> World::blockType;
map<UINT16, UINT16> World::floorLevel;


vector<short> World::randomStructArray;



Block* GetBlockBySymbol(char symbol) {
	for (UINT8 i = 0; i < World::blockType.size(); i++) {
		if (World::blockType[i]->symbol == symbol) {
			return World::blockType[i];
		}
	}
	return nullptr;

}

Block* GetBlockByIndex(short index) {
	for (UINT8 i = 0; i < World::blockType.size(); i++) {
		if (World::blockType[i]->index == index) {
			return World::blockType[i];
		}
	}
	return nullptr;
}

Block* GetBlockByCoords(UINT16 x, UINT16 y) {
	return GetBlockBySymbol(World::worldTemplate[y][x]);
}



void LoadBlock(string& target, short index) {
	target += GetBlockByIndex(index)->GetSymbol();
}

bool World::isCollisionEnabled(UINT16 x, UINT16 y) {
	return GetBlockByCoords(x, y)->IsCollisionEnabled();
}

UINT16 World::GetAverageFloorLevel() {
	return averageFloorLevel;
}

UINT16 World::GetSkyLevel() {
	return skyLevel;
}

UINT16 World::GetActualFloorLevel(UINT16 x) {
	auto result = floorLevel.find(x);
	return result->second;
}


void World::Init(Graphics* gfx) {

	blockType.push_back(new Block(imgSrc, gfx, '_', false, Block::air));
	blockType.push_back(new Block(imgSrc, gfx, '#', true,  Block::stone, 0, 20));
	blockType.push_back(new Block(imgSrc, gfx, '-', true,  Block::grass));
	blockType.push_back(new Block(imgSrc, gfx, '%', true, Block::dirt));
	blockType.push_back(new Block(imgSrc, gfx, '*', false, Block::cave, 0, 10));
	blockType.push_back(new Block(imgSrc, gfx, '&' ,true,  Block::diamond, 2, 5));
	
	floorLevelInit();
	randomArrayInit();
	worldTemplateInit();
#if DEBUG_MODE
	printVector(randomStructArray);
#endif
}



void World::Render() {
	static bool isDisplayed = false;

	for (UINT8 i = 0; i < worldTemplate.size(); i++) {
		for (UINT8 j = 0; j < worldTemplate[i].length(); j++) {
			GetBlockBySymbol(worldTemplate[i].at(j))->Render(j, i);
		}
	}
#if DEBUG_MODE
	if (!isDisplayed) {
		printVector(worldTemplate,"\n");
		isDisplayed = true;
	}
#endif
}

void World::Update() {

}



void World::randomArrayInit() {

	for (UINT8 i = 0; i < blockType.size(); i++) {
		if (blockType[i]->GetIndex() == Block::air) continue;
		if (blockType[i]->GetIndex() == Block::grass) continue;
		for (UINT16 j = 0; j < blockType[i]->GetSeed(); j++) {
			randomStructArray.push_back(blockType[i]->GetIndex());
		}
	}

}



void World::worldTemplateInit(void) {

	for (UINT8 i = 0; i < blocksCountY; i++) {
		worldTemplate.push_back("");
		for (UINT8 j = 0; j < blocksCountX; j++) {
			TerrainGenerator(worldTemplate[i], i, &j);
		}
	}
	
}

void World::floorLevelInit() {

	for (UINT16 i = 0; i <= blocksCountX; i++) {
		UINT16 actualFloorLevel = randint(averageFloorLevel, averageFloorLevel + 2);
		floorLevel.insert(pair<UINT16, UINT16>(i,actualFloorLevel));
	}
}





void World::TerrainGenerator(string& target, short deepness, UINT8* iterator) {
	int pick = randomStructArray[Utils::randint(0,randomStructArray.size())];

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




void World::GenerateCave(string& target, short deepness, UINT8* iterator) {
	if (!iterator) return;
	for (UINT8 i = 0; i < randint(3,8) && *iterator < blocksCountX; i++) {
		LoadBlock(target, Block::cave);
		(*iterator)++;
	}
	(*iterator)--;
}