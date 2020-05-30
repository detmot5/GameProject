#include "GameController.h"
#include "Character.h"


Character::Character(LPCTSTR bitmapPath, Graphics* graphics, float x, float y, float xSpeed,
	float ySpeed, float jumpHeight, float gravity)
	: Animation(bitmapPath, graphics, new GamePoint(x,y), new GameVector(xSpeed,ySpeed), new GameVector(0,gravity) , false)
{
	
}




void Character::Update(double timeDelta)
{


	if (GetAsyncKeyState(Right) & 0x8000)
	{
		MoveRight();
	}
	else if (GetAsyncKeyState(Left) & 0x8000)
	{
		MoveLeft();
	}
	else
	{
		index = 0;
	}
	//if (GetAsyncKeyState(Up) & 0x8000 || (World::actualChunk->isCollisionEnabled(x /32, y / 32) && flag == true))
	//{
	//	//MoveUp();
	//}
}

void Character::Render()
{
	Animation::Render();

}




void Character::MoveUp()
{

	
}

void Character::MoveRight()
{
	index = 1;
	
	if(World::offset < WORLD_BORDER) World::offset += static_cast<int>(velocity->x);

}

void Character::MoveLeft()
{
	index = 2;
	if (World::offset / 32 > World::chunks.front()->GetStartPoint()) World::offset -= static_cast<int>(velocity->x);

}

