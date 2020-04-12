#pragma once

#include "framework.h"
#include <vector>
using namespace std;

class World {

	static void Init();
	static void Render();
	static void Update();
private:
	static vector<string> worldTemplate;
	static inline unsigned short blocksCountX = SCREEN_WIDTH/32;
	static inline unsigned short blocksCountY = SCREEN_HEIGHT/32;
	static inline unsigned short floorLevel = blocksCountY / 2;
};