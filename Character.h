#pragma once

#include "Graphics.h"
#include "Animation/Animation.h"
#include "Chunks/Chunk.h"
#include "World.h"

class Character : public Animation
{
public:


	Character(LPCTSTR bitmapPath, Graphics* graphics, int position = 200, int y = World::GetActualFloorLevel(SCREEN_WIDTH/64), float xSpeed = 4.0,
		float ySpeed = -1, float jumpHeight = 32, float gravity = 6);


private:


	void Render() override;
	void Update() override;


	void MoveRight() override;
	void MoveLeft() override;
	void MoveUp() override;

	int lowestLevel;

	enum Direction
	{
		Right = 'D',
		Left = 'A',
		Up = 0x20
	};
};