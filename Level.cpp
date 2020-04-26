#include "Level.h"
#include "GameController.h"
#include "Character.h"


#include "Animation/Animation.h"
#include "Clouds.h"

Animation* Hero;
Animation* Cloud;


// example level class






void Level::Load(){
    World::Init(gfx);


    Hero = new Character(L"../GameProject/Graphicss/slime_sprite.png", gfx);
    Cloud = new Clouds(L"../GameProject/Graphicss/Cloud.png", gfx);


 //   Character::Init(gfx);
    
}

void Level::Unload() {
 
}


void Level::Update() {
   /* Character::move();*/


    Hero->Update();
    Cloud->Update();
}


void Level::Render() {
    gfx->ClearScreen(0,0,0);
    World::Render();

    Hero->Render();
    Cloud->Render();


  //  Character::Render();
}




