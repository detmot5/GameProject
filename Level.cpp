#include "Level.h"



// example level class
Level::Level() {
    load = false;
}

Level::Level(wstring path) {
    this->path = path;
    load = true;
}


Level::~Level() {

}
void Level::Load(){

    if (load) World::Load(gfx, path);
    else World::Init(gfx);

    World::Init(gfx);
    Animations.push_back(new Character(L"GameProject/Graphicss/character.png", gfx));
    Animations.push_back(new Clouds(L"GameProject/Graphicss/Cloud.png", gfx));
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




