#pragma once

#include "Graphics.h"
#include "Animation/Animation.h"
#include "Chunks/Chunk.h"
#include "World.h"

class Character : public Animation
{
public:



	Character(LPCTSTR bitmapPath, Graphics* graphics, float x, float y = 320, float xSpeed = 4,
		float ySpeed = 0.2, float jumpHeight = 25, float gravity = 16.0, int acceleration = 500);

	~Character();
	void Render() override;
	void Update() override;


private:
	enum class Direction
	{
		null = 0,
		Right = 'D',
		Left = 'A',
		Up = 0x20
	};

	bool jumping;







	GameVector* feet;
	GameVector* head;
	GameVector* middle;
	int acceleration;

	void MoveRight() override;
	void MoveLeft() override;

	void UpdateCoordinates();
	void Jump();





	bool isOnLand();
	Direction isNextToWall();

};