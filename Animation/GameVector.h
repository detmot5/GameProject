#pragma once

#include "../framework.h"

using namespace std;


class GameVector
{
public:
	GameVector(float x = 0, float y = 0);

	float Length() const;
	float x, y;

    GameVector operator*(float s) const;
	GameVector operator/(float s) const;

	friend GameVector operator-(GameVector a, GameVector b);
	friend GameVector operator+(GameVector a, GameVector b);
};


