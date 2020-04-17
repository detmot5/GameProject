#include "Level.h"
#include "GameController.h"



// example level class






void Level::Load(){
    World::Init(gfx);
}

void Level::Unload() {
 
}
void Level::Update() {

}


void Level::Render() {
    gfx->ClearScreen(0,0,0);
    World::Render();


}




