#include "GameController.h"
#include "Character.h"


Character::Character(LPCTSTR bitmapPath, Graphics* graphics, float x, float y, float xSpeed,
	float ySpeed, float jumpHeight, float gravity)
	: Animation(bitmapPath, graphics, new GameVector(x,y), new GameVector(xSpeed,0), new GameVector(8,gravity) , false)
{
	position->x = World::offset + SCREEN_WIDTH / 2;

	feet = new GameVector(position->x + DEFAULT_BLOCK_SIZE / 2, position->y + DEFAULT_BLOCK_SIZE);
	head = new GameVector(position->x + DEFAULT_BLOCK_SIZE / 2, position->y);
	middle = new GameVector(position->x + DEFAULT_BLOCK_SIZE / 2, position->y + DEFAULT_BLOCK_SIZE / 2);
	jumping = false;

}




void Character::Update()
{
	Animation::Update();
	UpdateCoordinates();


	if (GetAsyncKeyState(static_cast<int>(Direction::Right)) & 0x8000 && isNextToWall() != Direction::Right)  MoveRight();
	
	else if (GetAsyncKeyState(static_cast<int>(Direction::Left)) & 0x8000 && isNextToWall() != Direction::Left) MoveLeft();

	else index = 0;
	

	
	if (isOnLand()) {
		if(!jumping) velocity->y = 0;
		if (GetAsyncKeyState(static_cast<int>(Direction::Up)) & 0x8000) {
			Jump();
			jumping = true;
		} else jumping = false;
	}
	

	GravityEvent();
	

	
	
}

void Character::Render()
{
	Animation::Render();

}


void Character::Jump() {

	if (position->y >= SCREEN_HEIGHT / 4  && position->y < SCREEN_HEIGHT) {
		velocity->y = -500.0f;
	} else jumping = false;
	


	
}


bool Character::isOnLand() {
	int startPoint = World::actualChunk->GetStartPoint();
	/*if ((feet->x) / 32 - startPoint - 2 > 25 ) {
		cout << "ERR" << (feet->x) / 32 - startPoint << endl;

		while (1);
		co ja kurwa robie ze swoim zyciem
	}*/
		cout <<" "<< feet->x/32 << " ";
	if (World::actualChunk->isCollisionEnabled(feet->x / 32.0, feet->y / 32.0f)) {
		return true;
	}
	return false;
}


Character::Direction Character::isNextToWall() {
	//if (World::actualChunk->isCollisionEnabled(floor(static_cast<double>((feet->x + 10.0) / 32.0)), feet->y / 32))
	//	return Direction::Right;
	//else if (World::actualChunk->isCollisionEnabled(ceil(static_cast<double>((feet->x - 10.0) / 32.0)), feet->y / 32))
	//	return Direction::Left;

	return Direction::null;
}



void Character::UpdateCoordinates() {
	feet->x = World::offset + SCREEN_WIDTH / 2 + DEFAULT_BLOCK_SIZE / 2;
	feet->y = position->y + DEFAULT_BLOCK_SIZE;

	head->x = World::offset + SCREEN_WIDTH / 2 + DEFAULT_BLOCK_SIZE / 2;
	head->y = position->y;

	middle->x = World::offset + SCREEN_WIDTH / 2 + DEFAULT_BLOCK_SIZE / 2;
	middle->y = position->y + DEFAULT_BLOCK_SIZE / 2;

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

