#include "Level.h"
#include "Menu/Menu.h"


// example level class




void Level::Load(){
    World::Init(gfx);

    Animations.push_back(new Character(L"GameProject/Graphicss/character.png", gfx));
    Animations.push_back(new Clouds(L"GameProject/Graphicss/Cloud.png", gfx));


}


Level::~Level() {
}

void Level::Unload() {
    World::Unload();

}



void Level::Update() {
    World::Update();
    for (auto i : Animations)  i->Update();
    
}

void Level::Render() {
    gfx->ClearScreen(0,0,0);
    World::Render();

    for (auto i : Animations) i->Render();
}




