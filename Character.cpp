#include "GameController.h"
#include "Character.h"

using namespace Utils;

Character::Character(LPCTSTR bitmapPath, Graphics* graphics, float x, float y, float xSpeed,
	float ySpeed, float jumpHeight, float gravity, int acceleration)
	: Animation(bitmapPath, graphics, new GameVector(x, y), new GameVector(xSpeed, 0), new GameVector(0, gravity), false)
{
	World::offset = 0;
	position->x = static_cast<float>(World::offset + SCREEN_WIDTH / 2);
	feet = new GameVector(position->x + DEFAULT_BLOCK_SIZE / 2, position->y + DEFAULT_BLOCK_SIZE);
	head = new GameVector(position->x + DEFAULT_BLOCK_SIZE / 2, position->y);
	middle = new GameVector(position->x + DEFAULT_BLOCK_SIZE / 2, position->y + DEFAULT_BLOCK_SIZE / 2);
	jumping = false;
	this->acceleration = acceleration;
}

Character::~Character() {
	Animation::~Animation();
	delete position;
	delete feet;
	delete head;
	delete middle;
}



void Character::Update()
{
	Animation::Update();
	UpdateCoordinates();


	if (GetAsyncKeyState(static_cast<int>(Direction::Right)) & 0x8000 && isNextToWall() != Direction::Right)  MoveRight();

	else if (GetAsyncKeyState(static_cast<int>(Direction::Left)) & 0x8000 && isNextToWall() != Direction::Left) MoveLeft();

	else index = 0;

	// if character would get stuck
	if (GetAsyncKeyState(VK_HOME) & 0x8000) {

		position->y = SCREEN_HEIGHT / 4;
		position->x = SCREEN_WIDTH / 2;
	}

	if (isOnLand()) {
		if (!jumping) velocity->y = 0;
		if (GetAsyncKeyState(static_cast<int>(Direction::Up)) & 0x8000) {
			Jump();
			jumping = true;
		}
		else jumping = false;
	}
	else if (World::isCollisionEnabled(convertToBlockCoord(head->x), convertToBlockCoord(head->y - 10))) {
		velocity->y = static_cast<float>(acceleration);
	}

	GravityEvent();


}

void Character::Render()
{
	Animation::Render();

}



void Character::Jump() {

	if (position->y >= SCREEN_HEIGHT / 4 && position->y < SCREEN_HEIGHT) {
		velocity->y = static_cast<float>(-acceleration);
	}
	else jumping = false;

}


bool Character::isOnLand() {

	if (World::isCollisionEnabled(convertToBlockCoord(feet->x), convertToBlockCoord(feet->y)))
		return true;

	return false;
}




Character::Direction Character::isNextToWall() {
	if (World::isCollisionEnabled(convertToBlockCoord(middle->x + 8), convertToBlockCoord(middle->y)))
		return Direction::Right;
	else if (World::isCollisionEnabled(convertToBlockCoord(middle->x - 8), convertToBlockCoord(middle->y)))
		return Direction::Left;

	return Direction::null;
}



void Character::UpdateCoordinates() {
	feet->x = static_cast<float>(World::offset + SCREEN_WIDTH / 2 + DEFAULT_BLOCK_SIZE / 2);
	feet->y = position->y + DEFAULT_BLOCK_SIZE;

	head->x = static_cast<float>(World::offset + SCREEN_WIDTH / 2 + DEFAULT_BLOCK_SIZE / 2);
	head->y = position->y + DEFAULT_BLOCK_SIZE / 2;

	middle->x = static_cast<float>(World::offset + SCREEN_WIDTH / 2 + DEFAULT_BLOCK_SIZE / 2);
	middle->y = position->y + DEFAULT_BLOCK_SIZE / 2;

}





void Character::MoveRight()
{
	index = 1;
	if (World::offset < WORLD_BORDER) World::offset += static_cast<int>(velocity->x);

}

void Character::MoveLeft() {
	index = 2;
	if (convertToBlockCoord(static_cast<float>(World::offset)) > World::chunks.front()->GetStartPoint()) World::offset -= static_cast<int>(velocity->x);

}
