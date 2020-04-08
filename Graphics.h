#pragma once
#include <d2d1.h>
#include "framework.h"


class Graphics {
public:
	Graphics();
	~Graphics();
	bool Init(HWND windowHandler);
	void beginDraw() { renderTarget->BeginDraw(); };
	void endDraw() { renderTarget->EndDraw(); };

	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a);

	ID2D1RenderTarget* GetRenderTarget() { return renderTarget; };


private:
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	
};