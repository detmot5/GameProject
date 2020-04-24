#include "Level.h"
#include "GameController.h"
#include "Character.h"

Character* Steve;

// example level class






void Level::Load(){
    World::Init(gfx);
    Steve = new Character(gfx);
}

void Level::Unload() {
 
}


void Level::Update() {
    Steve->Update();
}


void Level::Render() {
    gfx->ClearScreen(0,0,0);
    World::Render();

    Steve->Render();
}




