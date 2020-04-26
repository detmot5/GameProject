#pragma once

#include "Animation/Animation.h"

class Clouds : public Animation
{
public:
	Clouds(LPCTSTR bitmapPath, Graphics* graphics, float x = SCREEN_WIDTH / SCREEN_WIDTH - 1, float y = (int)(SCREEN_HEIGHT * 0.10), float xSpeed = 2.0);
	void Update() override;
	void Render() override;

private:
	void MoveRight() override;
};