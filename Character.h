#pragma once

#include "Graphics.h"
#include "Animation/Animation.h"
#include "Chunks/Chunk.h"
#include "World.h"

class Character : public Animation
{
public:


	Character(LPCTSTR bitmapPath, Graphics* graphics, float x , float y = SCREEN_WIDTH/64 + 64, float xSpeed = 8,
		float ySpeed = 0.2, float jumpHeight = 25, float gravity = 6.0);


private:


	void Render() override;
	void Update(double timeDelta) override;


	void MoveRight() override;
	void MoveLeft() override;
	void MoveUp() override;


	enum Direction
	{
		Right = 'D',
		Left = 'A',
		Up = 0x20
	};
};