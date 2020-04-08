#include "Graphics.h"

Graphics::Graphics(void) {
	factory = NULL;
	renderTarget = NULL;
}

Graphics::~Graphics(void) {
		// Te wskazniki s¹ do jakichs komponentow karty graficznej
		// One nie s¹ optymalizowane pamieciowo wiec musimy je rêcznie zwalniaæ
	if (factory) factory->Release();
	if (renderTarget) renderTarget->Release();
}

bool Graphics::Init(HWND windowHandler) {
	HRESULT hres = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED,&factory);
	if (hres != S_OK) return false;
	RECT rect;
	GetClientRect(windowHandler, &rect);
	hres = factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(windowHandler,D2D1::SizeU(rect.right,rect.bottom)),
		&renderTarget
	);
	if (hres != S_OK) return false;
	return true;
}

void Graphics::ClearScreen(float r, float g, float b) {
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}
void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a) {
	ID2D1SolidColorBrush* brush;
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(r,g,b,a),&brush);
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, 3.0f);
	

	brush->Release();
}