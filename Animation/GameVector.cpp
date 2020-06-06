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

GameVector GameVector::operator*(float s) const{
	GameVector scaled;
	scaled.x = x * s;
	scaled.y = y * s;
	return scaled;
}

GameVector GameVector::operator/(float s) const {
	GameVector scaled;
	scaled.x = x / s;
	scaled.y = y / s;
	return scaled;
}

GameVector operator-(GameVector a, GameVector b) {
	GameVector v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	return v;
}

GameVector operator+(GameVector a, GameVector b) {
	GameVector v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	return v;
}





