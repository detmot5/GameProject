#include "Level.h"



// example level class



void Level::Load(){
    World::Init(gfx);
    Animations.push_back(new Character(L"../GameProject/Graphicss/character.png", gfx));
    Animations.push_back(new Clouds(L"../GameProject/Graphicss/Cloud.png", gfx));


}

void Level::Unload() {
 
}



void Level::Update() {
    for (UINT8 i = 0; i < Animations.size(); i++) {
        Animations[i]->Update();
    }
}

void Level::Render() {
    gfx->ClearScreen(0,0,0);
    World::Render();

    for (UINT8 i = 0; i < Animations.size(); i++) {
        Animations[i]->Render();
    }
}




