#include "World.h"


vector<string> World::worldTemplate;


void World::Init() {
	for (int i = 0; i < blocksCountY; i++) {
		worldTemplate.push_back("");
		for (int j = 0; j < blocksCountX; j++) {
			if (i > 10) {
				worldTemplate[i] += "#";
			}
			else if (i <= 10) {
				worldTemplate[i] += "*";
			}
		}
	}
}



void World::Render() {
	
	for (vector<string>::iterator i = worldTemplate.begin(); i != worldTemplate.end(); i++) {
		for (int j = 0; j < (*i).length(); j++) {
			
		}
	}



}

void World::Update() {

}
