#include "World.h"


vector<string> World::worldTemplate;
vector<Block*> World::blockType;
vector<short> World::randomArray = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,

};

void (*World::RandomStructGenerator[])(string&, short, UINT8*) {
		caveGenerator,
		terrainGenerator,
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
	blockType.push_back(new Block(imgSrc, gfx, '#', true,  Block::stone));
	blockType.push_back(new Block(imgSrc, gfx, '-', true,  Block::grass));
	blockType.push_back(new Block(imgSrc, gfx, '*', false, Block::cave));
	blockType.push_back(new Block(imgSrc, gfx, '&' ,true,  Block::diamond, 2, 2));

	randomArrayInitialize();
	worldTemplateInitialize();
}



void World::Render() {
	for (UINT8 i = 0; i < worldTemplate.size(); i++) {
		for (UINT8 j = 0; j < worldTemplate[i].length(); j++) {
			GetBlockBySymbol(worldTemplate[i].at(j))->Render(j, i);
		}
	}
}

void World::Update() {

}









void World::randomArrayInitialize() {

	//for (short i = 0; i < 50; i++) {
	//	randomArray.push_back(Block::stone);
	//}
	//for
	//	

}



void World::worldTemplateInitialize(void) {
	srand((unsigned int)time(nullptr));


	for (UINT8 i = 0; i < blocksCountY; i++) {
		worldTemplate.push_back("");
		for (UINT8 j = 0; j < blocksCountX; j++) {
			if (i > floorLevel) {
				RandomStructGenerator[randomArray[rand() % randomArray.size()]](worldTemplate[i], i, &j);
			}
			else if (i < floorLevel) {
				worldTemplate[i] += GetBlockByIndex(Block::air)->GetSymbol();

			}
			else if(i == floorLevel) {
				worldTemplate[i] += GetBlockByIndex(Block::grass)->GetSymbol();
			}

		}
	}
	
}






void World::airGenerator(string& target, short deepness, UINT8* iterator) {
	target += GetBlockByIndex(Block::air)->GetSymbol();
}

void World::terrainGenerator(string& target, short deepness, UINT8* iterator) {


	//target += GetBlockByIndex(Block::stone)->GetSymbol();

	//enum TerrainTypes { dirt = 0, stone = 1, diamond = 2 };
	vector <int> randArr;
	for (int i = 0; i < GetBlockByIndex(Block::stone)->GetSeed(); i++) {
		randArr.push_back(Block::stone);
	}
	randArr.push_back(Block::diamond);

	int pick = randArr[rand() % randArr.size()];


	switch (pick) {
	case Block::diamond: 
		if (deepness >= blocksCountY - 2) {
			target += GetBlockByIndex(Block::diamond)->GetSymbol();
		}
		else target += "#"; break;
	case Block::stone: target += '#'; break;
	////case dirt: target += '@'; break;
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