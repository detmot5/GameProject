#pragma once

#include "Graphics.h"
#include "Animation/Animation.h"
#include "Chunks/Chunk.h"
#include "World.h"

class Character : public Animation
{
public:


<<<<<<< HEAD
	Character(LPCTSTR bitmapPath, Graphics* graphics, float x , float y = 320, float xSpeed = 4,
		float ySpeed = 0.2, float jumpHeight = 25, float gravity = 16.0, int acceleration = 500);


private:
	enum class Direction
	{
		null = 0,
		Right = 'D',
		Left = 'A',
		Up = 0x20
	};

	bool jumping;
=======
	Character(LPCTSTR bitmapPath, Graphics* graphics, int position = SCREEN_WIDTH/2 + 10, int y = World::GetActualFloorLevel(SCREEN_WIDTH/64), float xSpeed = 4.0,
		float ySpeed = -0.2, float jumpHeight = 25, float gravity = 6.0);


private:

>>>>>>> menu

	void Render() override;
	void Update() override;


<<<<<<< HEAD


	GameVector* feet;
	GameVector* head;
	GameVector* middle;
	int acceleration;
=======
>>>>>>> menu
	void MoveRight() override;
	void MoveLeft() override;
	void MoveUp() override;

<<<<<<< HEAD
	void UpdateCoordinates();
	void Jump();

	



	bool isOnLand();
	Direction isNextToWall();



=======
	int lowestLevel;

	enum Direction
	{
		Right = 'D',
		Left = 'A',
		Up = 0x20
	};
>>>>>>> menu
};