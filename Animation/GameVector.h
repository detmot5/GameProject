#pragma once

#include "../framework.h"
#include "Point.h"
using namespace std;


class GameVector
{
public:
	GameVector(float x = 0, float y = 0);

	float Length() const;
	float x, y;


//	friend GameVector operator-(Point a, Point b);
};


