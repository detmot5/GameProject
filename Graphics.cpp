#include "Graphics.h"

//#include <windows.h>

Graphics::Graphics(void) {
	factory = NULL;
	writeFactory = NULL;
	renderTarget = NULL;
	
}

Graphics::~Graphics(void) {
	// Te wskazniki s¹ do jakichs komponentow karty graficznej
	// One nie s¹ optymalizowane pamieciowo wiec musimy je rêcznie zwalniaæ
	if (factory) factory->Release();
	if (writeFactory) writeFactory->Release();
	if (renderTarget) renderTarget->Release();
}

bool Graphics::Init(HWND windowHandler) {
	HRESULT hres = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if (hres != S_OK) return false;
	RECT rect;
	GetClientRect(windowHandler, &rect);
	hres = factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(windowHandler, D2D1::SizeU(rect.right, rect.bottom)),
		&renderTarget
	);
	if (hres != S_OK) return false;



	hres = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&writeFactory));

	if (hres != S_OK) return false;

	hres = writeFactory->CreateTextFormat(
		L"Gabriola",
		NULL,
		DWRITE_FONT_WEIGHT_REGULAR,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		12,
		L"en-us",
		&textFormat
	);
	if (hres != S_OK) return false;


	return true;
}

void Graphics::ClearScreen(float r, float g, float b) {
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}
void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a) {
	ID2D1SolidColorBrush* brush;
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);
	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, 3.0f);


	brush->Release();
}



bool Graphics::Print(const WCHAR* str, D2D_RECT_F& rect, UINT8 fontSize, const WCHAR* fontStyle)
{


	ID2D1SolidColorBrush* brush;
	HRESULT hres;


	hres = writeFactory->CreateTextFormat(
		fontStyle,
		NULL,
		DWRITE_FONT_WEIGHT_REGULAR,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		fontSize,
		L"en-us",
		&textFormat
	);

	if (hres != S_OK) return false;

	
	renderTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0), &brush);

	renderTarget->DrawTextW(
		str,
		wcslen(str),
		textFormat,
		rect,
		brush
		);
			
	return true;
}