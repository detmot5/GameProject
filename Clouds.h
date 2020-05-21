#pragma once

#include "Animation/Animation.h"

class Clouds : public Animation
{
public:


	Clouds(LPCTSTR bitmapPath, Graphics* graphics, int x = SCREEN_WIDTH / SCREEN_WIDTH - 1, 
		int y = (SCREEN_HEIGHT * 0.10), float xSpeed = 0.02);
	

private:


	void Update() override;
};