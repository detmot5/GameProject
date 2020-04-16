#include "World.h"
#include <iostream>
vector<string> World::worldTemplate;
vector<Block*> World::blockType;
vector<short> World::randomArray = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0

};

void (*World::RandomStructGenerator[])(string&, short, int*) {
		airGenerator,
		terrainGenerator,
		caveGenerator,
};


Block* GetBlockBySymbol(char symbol) {
	for (int i = 0; i < World::blockType.size(); i++) {
		if (World::blockType[i]->symbol == symbol) {
			return World::blockType[i];
		}
	}
	return nullptr;

}

Block* GetBlockByIndex(short index) {
	for (short i = 0; i < World::blockType.size(); i++) {
		if (World::blockType[i]->index == index) {
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


	for (int i = 0; i < blocksCountY; i++) {
		worldTemplate.push_back("");
		for (int j = 0; j < blocksCountX; j++) {
			if (i > floorLevel) {
				//worldTemplate[i] += "#";
				RandomStructGenerator[randomArray[rand() % randomArray.size()]](worldTemplate[i], i, &j);
			}
			else if (i <= floorLevel) {
				//worldTemplate[i] += "_";
				RandomStructGenerator[0](worldTemplate[i], 0, nullptr);
			}

		}
	}
	cout << "done" << endl;
}






void World::airGenerator(string& target, short deepness, int* iterator) {
	target += "_";
}

void World::terrainGenerator(string& target, short deepness, int* iterator) {


	target += "#";

	//enum TerrainTypes { dirt = 0, stone = 1, diamond = 2 };
	//vector <int> randArr;
	//for (int i = 0; i < 50; i++) {
	//	randArr.push_back(dirt);
	//	randArr.push_back(stone);
	//}
	//randArr.push_back(diamond);

	//int pick = randArr[rand() % randArr.size()];


	//switch (pick) {
	////case diamond: if (deepness >= blocksCountY - 2)  target += "_"; else target += "#"; break;
	//case stone: target += '#'; break;
	////case dirt: target += '@'; break;
	//}


}

void World::caveGenerator(string& target, short deepness, int* iterator) {
	if (!iterator) return;
	for (int i = 0; i < (rand() % 6) + 2 && *iterator < blocksCountX; i++) {
		target += GetBlockByIndex(Block::air)->GetSymbol();
		(*iterator)++;
	}
	(*iterator)--;
}