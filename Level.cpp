#include "Level.h"



// example level class


Level::Level(wstring path, bool load) {
    this->path = path;
    this->load = load;
}


Level::~Level() {

}
void Level::Load(){

    if (load) World::Load(gfx, path);
    else World::Init(gfx,path);
    Animations.push_back(new Character(L"GameProject/Graphicss/character.png", gfx, SCREEN_WIDTH / 2, SCREEN_WIDTH / 64 + 64, 80));
    Animations.push_back(new Clouds(L"GameProject/Graphicss/Cloud.png", gfx));
}




void Level::Unload() {
    World::Unload();

}



void Level::Update(double timeTotal, double timeDelta) {
    World::Update();
    for (auto i : Animations)  i->Update(timeDelta);
    
}

void Level::Render() {
    gfx->ClearScreen(0,0,0);
    World::Render();

    for (auto i : Animations) i->Render();
}




