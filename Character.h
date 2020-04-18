#pragma once
#include "Graphics.h"

class Character
{
public:
	static int temp;
	void static Jump(Graphics* graphics);
	void static SinJump_L(Graphics* graphics);
	void static SinJump_R(Graphics* graphics);
	void static Right(Graphics* graphics);
	void static Left(Graphics* graphics);
};