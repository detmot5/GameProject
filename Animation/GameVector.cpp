#include "GameVector.h"


GameVector::GameVector(float x, float y){
	this->x = x;
	this->y = y;
}


float GameVector::Length() const {
	float length;
	length = sqrt(x * x + y * y);
	return length;
}

//GameVector operator-(Point a, Point b) {
//	GameVector v;
//
//	v.x = a.x - b.x;
//	v.y = a.y - b.y;
//	return v;
//}
//



