#include "Level.h"


Level::Level(bool load, wstring path) {
    this->path = path;
    this->load = load;
}



Level::~Level() {

}

void Level::Load() {
  
    if (load && path != L"") World::Load(gfx, path);
    else World::Init(gfx);

    Animations.push_back(new Character(Path::character, gfx, SCREEN_WIDTH / 2, SCREEN_WIDTH / 64 + 64, 6));
}




void Level::Unload() {
    World::Unload();
    Animations.clear();
    cout << "poszlo" << endl;
    delete this;
}



void Level::Update() {
    World::Update();
    for (auto i : Animations)  i->Update();
    // cout << timeDelta << endl;
   // chr->Update();

}

void Level::Render() {
    gfx->ClearScreen(0, 0, 0);
    World::Render();
    for (auto i : Animations) i->Render();
}