#pragma once

#include "Graphics.h"
#include "Animation/Animation.h"
#include "Chunks/Chunk.h"
#include "World.h"

class Character : public Animation
{
public:


	Character(LPCTSTR bitmapPath, Graphics* graphics, float x = SCREEN_WIDTH * 0.5, float y = World::GetActualFloorLevel(SCREEN_WIDTH/64), float xSpeed = 4.0,
		float ySpeed = -0.2, float jumpHeight = (SCREEN_HEIGHT * 0.03), float gravity = 4.0);


private:


	void Render() override;
	void Update() override;


	void MoveRight() override;
	void MoveLeft() override;
	void MoveUp() override;

	int lowestLand;
	enum Direction
	{
		Right = 'D',
		Left = 'A',
		Up = 0x20
	};
};