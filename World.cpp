#include "World.h"
using namespace Utils;

vector<string> World::worldTemplate;
vector<Block*> World::blockType;

vector<short> World::randomStructArray;

void (*World::RandomStructGenerator[])(string&, short, UINT8*) {
		TerrainGenerator,
		caveGenerator,
};


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



void World::Init(Graphics* gfx) {

	blockType.push_back(new Block(imgSrc, gfx, '_', false, Block::air));
	blockType.push_back(new Block(imgSrc, gfx, '#', true,  Block::stone, 0, 20));
	blockType.push_back(new Block(imgSrc, gfx, '-', true,  Block::grass));
	blockType.push_back(new Block(imgSrc, gfx, '%', true, Block::dirt));
	blockType.push_back(new Block(imgSrc, gfx, '*', false, Block::cave, 0, 10));
	blockType.push_back(new Block(imgSrc, gfx, '&' ,true,  Block::diamond, 2, 2));
	randomArrayInitialize();
	printVector(randomStructArray);
	worldTemplateInitialize();
}



void World::Render() {
	static bool isDisplayed = false;
	for (UINT8 i = 0; i < worldTemplate.size(); i++) {
		for (UINT8 j = 0; j < worldTemplate[i].length(); j++) {
			GetBlockBySymbol(worldTemplate[i].at(j))->Render(j, i);
		}
		if(!isDisplayed)
			cout << worldTemplate[i]<<endl;
	}
	isDisplayed = true;
}

void World::Update() {

}









void World::randomArrayInitialize() {

	for (int i = 0; i < blockType.size(); i++) {
		if (blockType[i]->GetIndex() == Block::air) continue;
		if (blockType[i]->GetIndex() == Block::grass) continue;
		for (int j = 0; j < blockType[i]->GetSeed(); j++) {
			randomStructArray.push_back(blockType[i]->GetIndex());
		}
	}

}



void World::worldTemplateInitialize(void) {
	srand(static_cast<unsigned int>(time(nullptr)));

	for (UINT8 i = 0; i < blocksCountY; i++) {
		worldTemplate.push_back("");
		for (UINT8 j = 0; j < blocksCountX; j++) {
			if (i >= floorLevel) {
				TerrainGenerator(worldTemplate[i], i, &j);
			}
			else if (i < floorLevel) {
				worldTemplate[i] += GetBlockByIndex(Block::air)->GetSymbol();

			}

		}
	}
	
}






void World::TerrainGenerator(string& target, short deepness, UINT8* iterator) {
	int pick = randomStructArray[Utils::randint(1,randomStructArray.size())];


	if (deepness == floorLevel) {
		target += GetBlockByIndex(Block::grass)->GetSymbol();
		return;
	}

	switch (pick) {
	case Block::diamond: 
		if (deepness >= blocksCountY - 2) {
			target += GetBlockByIndex(Block::diamond)->GetSymbol();
		}
		else target += GetBlockByIndex(Block::stone)->GetSymbol(); 
		break;

	case Block::stone: 
		target += GetBlockByIndex(Block::stone)->GetSymbol();
		break;

	case Block::dirt:
		if (0) {
			target += GetBlockByIndex(Block::dirt)->GetSymbol();
		}
		else {
			target += GetBlockByIndex(Block::stone)->GetSymbol();
		}
		break;

	case Block::cave:
		caveGenerator(target, 0, iterator);
#if DEBUG_MODE
		cout << "Cave gen start" << endl;
#endif
		break;

	}
}




void World::caveGenerator(string& target, short deepness, UINT8* iterator) {
	if (!iterator) return;
	for (UINT8 i = 0; i < i < (rand() % 6) && *iterator < blocksCountX; i++) {
		target += GetBlockByIndex(Block::cave)->GetSymbol();
		(*iterator)++;
	}
	(*iterator)--;
}