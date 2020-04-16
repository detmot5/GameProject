#include "World.h"

vector<string> World::worldTemplate;
vector<Block*> World::blockType;
vector<short> World::randomArray = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0

};

void (*World::RandomStructGenerator[])(string&, short, int*) {
		airGenerator,
		terrainGenerator,
		caveGenerator,
};


Block* getObjectBySymbol(char sym) {
	for (int i = 0; i < 10; i++) {
		if (World::blockType[i]->symbol == sym) {
			return World::blockType[i];
		}
	}
	return nullptr;

}



void World::Init(Graphics* gfx) {

	blockType.push_back(new Block(L"../source/Graphicss/block.png", gfx, '_', false, Block::air));
	blockType.push_back(new Block(L"../source/Graphicss/block.png", gfx, '#', true, Block::stone));

	randomArrayInitialize();
	worldTemplateInitialize();
}



void World::Render() {
	for (int i = 0; i < worldTemplate.size(); i++) {
		for (int j = 0; j < worldTemplate[i].length(); j++) {
			getObjectBySymbol(worldTemplate[i].at(j))->Render(j, i);
		}
	}
}

void World::Update() {

}









void World::randomArrayInitialize() {
	//for (short i = 0; i < blockType.size(); i++) {
	//	for (short j = 0; j < blockType[i]->GetSeed(); i++) {
	//		randomArray.push_back(i);
	//	}
	//}
		

}



void World::worldTemplateInitialize(void) {
	srand(time(nullptr));


	for (int i = 0; i < blocksCountY; i++) {
		worldTemplate.push_back("");
		for (int j = 0; j < blocksCountX; j++) {
			if (i > floorLevel) {
				worldTemplate[i] += "#";
				//RandomStructGenerator[randomArray[rand() % randomArray.size()]](worldTemplate[i], i, &j);
			}
			else if (i <= floorLevel) {
				worldTemplate[i] += "_";
				//RandomStructGenerator[0](worldTemplate[i], 0, nullptr);
			}

		}
	}
}






void World::airGenerator(string& target, short deepness, int* iterator) {
	target += "_";
}

void World::terrainGenerator(string& target, short deepness, int* iterator) {

	enum TerrainTypes { dirt = 0, stone = 1, diamond = 2 };
	vector <int> randArr;
	for (int i = 0; i < 50; i++) {
		randArr.push_back(dirt);
		randArr.push_back(stone);
	}
	randArr.push_back(diamond);

	int pick = randArr[rand() % randArr.size()];


	switch (pick) {
	//case diamond: if (deepness >= blocksCountY - 2)  target += "_"; else target += "#"; break;
	case stone: target += '#'; break;
	//case dirt: target += '@'; break;
	}


}

void World::caveGenerator(string& target, short deepness, int* iterator) {
	if (!iterator) return;
	for (int i = 0; i < rand() % 8 && *iterator < 25; i++) {
		target += ".";
		(*iterator)++;
	}
	(*iterator)--;
}