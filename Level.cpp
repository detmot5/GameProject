#include "Level.h"
#include "GameController.h"


// example level class






void Level::Load(){
    World::Init(gfx);
}

void Level::Unload() {
 
}
void Level::Update() {
    ySpeed += 1.0f;
    y += ySpeed;
    if (y > SCREEN_HEIGHT - 100) {
        y = SCREEN_HEIGHT - 100;
        ySpeed = -30;
    }
    frame++;
}


void Level::Render() {
    //gfx->ClearScreen(0.0f, 0.9f, 0.3f);
    ///*sprites->Draw((frame / 5) % 5, 100, 100);
    //sprites->Draw((frame / 5) % 5, 200, 200);
    //sprites->Draw((frame / 5) % 5, 300, 300);*/
    ////blockTypes[0]->Render(2, 8);
    ////blockTypes[1]->Render(1, 8);
    ////block->Render(2, 5);
    //gfx->DrawCircle(700, y, 50,0.5,0.5,0.5,1); 
    World::Render();


}




