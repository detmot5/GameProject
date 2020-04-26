#pragma once

#include "Graphics.h"
#include "Animation/Animation.h"

class Character : public Animation
{
public:
	Character(LPCTSTR bitmapPath, Graphics* graphics, float x = SCREEN_WIDTH * 0.5, 
				float y = (int)(SCREEN_HEIGHT * 0.47), float xSpeed = 4.0, float ySpeed = 4);

	void Update() override;
	void Render() override;

private:
	void MoveRight() override;
	void MoveLeft() override;
	void MoveUp() override;
	void MoveDown() override;

	enum Direction
	{
		Right = 'D',
		Left = 'A',
		Up = 0x20
	};

	enum indicator
	{
		On = 1,
		Off = 0
	};

};