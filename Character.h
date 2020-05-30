#pragma once

#include "Graphics.h"
#include "Animation/Animation.h"
#include "Chunks/Chunk.h"
#include "World.h"

class Character : public Animation
{
public:


	Character(LPCTSTR bitmapPath, Graphics* graphics, int position = SCREEN_WIDTH/2 + 10, int y = SCREEN_WIDTH/64 + 64, float xSpeed = 8,
		float ySpeed = -0.2, float jumpHeight = 25, float gravity = 6.0);


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