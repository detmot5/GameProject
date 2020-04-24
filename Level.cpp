#include "Level.h"
#include "GameController.h"
#include "Character.h"



// example level class






void Level::Load(){
    World::Init(gfx);
    Character::Init(gfx);
    
}

void Level::Unload() {
 
}


void Level::Update() {
    Character::move();
}


void Level::Render() {
    gfx->ClearScreen(0,0,0);
    World::Render();

    Character::Render();
}




