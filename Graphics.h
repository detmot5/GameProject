#pragma once
#include <d2d1.h>
#include <dwrite.h>
#include "framework.h"
using namespace std;

class Graphics {
public:
	Graphics();
	~Graphics();
	bool Init(HWND windowHandler);
	void beginDraw() { renderTarget->BeginDraw(); };
	void endDraw() { renderTarget->EndDraw(); };

	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a);

	bool Print(const WCHAR* str, D2D_RECT_F& rect, UINT8 fontSize = 12, const WCHAR* fontStyle = L"Arial");

	ID2D1RenderTarget* GetRenderTarget() { return renderTarget; };

private:
	
	ID2D1Factory* factory;
	IDWriteFactory* writeFactory;
	IDWriteTextFormat* textFormat;
	ID2D1HwndRenderTarget* renderTarget;



	
};
