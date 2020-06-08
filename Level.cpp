#include "Level.h"
<<<<<<< HEAD
=======
#include "Menu/Menu.h"
>>>>>>> menu


// example level class
Level::Level() {
    load = false;
}

Level::Level(wstring path) {
    this->path = path;
    load = true;
}

Level::Level(wstring path, bool load) {
    this->path = path;
    this->load = load;
    

<<<<<<< HEAD
}


Level::~Level() {

=======
Level::~Level() {

>>>>>>> menu
}
void Level::Load(){

    if (load) World::Load(gfx, path);
<<<<<<< HEAD
    else World::Init(gfx,path);
    
    Animations.push_back(new Character(Path::character, gfx, SCREEN_WIDTH/2, SCREEN_WIDTH / 64 + 64, 6));
    Animations.push_back(new Clouds(Path::cloud, gfx));
}

 
=======
    else World::Init(gfx);
    Animations.push_back(new Character(L"GameProject/Graphicss/character.png", gfx));
    Animations.push_back(new Clouds(L"GameProject/Graphicss/Cloud.png", gfx));
}


>>>>>>> menu


void Level::Unload() {
    World::Unload();

}



void Level::Update() {
    World::Update();
    for (auto i : Animations)  i->Update();
<<<<<<< HEAD
   // cout << timeDelta << endl;
=======
>>>>>>> menu
    
}

void Level::Render() {
    gfx->ClearScreen(0,0,0);
    World::Render();

    for (auto i : Animations) i->Render();
}




