#include "SpriteSheet.h"




SpriteSheet::SpriteSheet(LPCWSTR filename, Graphics* gfx) {
	this->gfx = gfx;
	bmp = NULL;
	HRESULT hr;
//------------------------------------------------------------------------------------------------
// WIC factory make. It can be used to load images from files. Call CoCreateInstance to create it
//------------------------------------------------------------------------------------------------


	IWICImagingFactory* wicFactory = NULL;
	hr = CoCreateInstance(
		CLSID_WICImagingFactory,			// CLS ID of the object we're making
		NULL,								// Not part of an aggregate
		CLSCTX_INPROC_SERVER,				// DLL runs in the same proces
		IID_IWICImagingFactory,				// Ref to interface that
		(LPVOID*)&wicFactory				// The pointer that will contain our factory
	);

	IWICBitmapDecoder* wicDecoder = NULL;

// Create a decoder
	hr = wicFactory->CreateDecoderFromFilename(
		filename,							// The file name
		NULL,								// No preferred vendor
		GENERIC_READ,						// We're reading the file, nor writing
		WICDecodeMetadataCacheOnLoad,		// Cache on load*
		&wicDecoder							// The our decoder we're making
	);

// pobieramy klatke naszego obrazu - ta liczba przy getframe to numer klatki - jezeli gif
	IWICBitmapFrameDecode* wicFrame = nullptr;
	hr = wicDecoder->GetFrame(0, &wicFrame);

	IWICFormatConverter* wicConverter = NULL;
	hr = wicFactory->CreateFormatConverter(&wicConverter);

	// setup converter
	hr = wicConverter->Initialize(
		wicFrame,
		GUID_WICPixelFormat32bppPRGBA,	// pixel format - WIC pixel - 32bbp (bit per pixel)  color palette - RGBA
		WICBitmapDitherTypeNone,		// irrevelant
		NULL,							// no pallete needed - irrevelent
		0.0,							// Alpha transparency - irrevelant
		WICBitmapPaletteTypeCustom		// irrevelant
	);

	// Use converter to crate D2D1Bitmap - finally

	hr = gfx->GetRenderTarget()->CreateBitmapFromWicBitmap(
		wicConverter,
		NULL,
		&bmp
	);

	// now we don't need this WIC objects
	if (wicFactory) wicFactory->Release();
	if (wicDecoder) wicDecoder->Release();
	if (wicConverter) wicConverter->Release();
	if (wicFrame) wicFrame->Release();
	
	spriteWidth = bmp->GetSize().width;
	spriteHeight = bmp->GetSize().height;
	spritesAccross = 1;
}

SpriteSheet::SpriteSheet(LPCWSTR filename, Graphics* gfx, int spriteWidth, int spriteHeight) : SpriteSheet(filename,gfx){
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->spritesAccross = static_cast<int>(bmp->GetSize().width) / spriteWidth;
}



SpriteSheet::~SpriteSheet() {
	if (bmp) bmp->Release();
}
//draw bitmap to the render target
void SpriteSheet::Draw() {
	gfx->GetRenderTarget()->DrawBitmap(
		bmp,
		D2D1::RectF(0.0f, 0.0f, 
			bmp->GetSize().width, bmp->GetSize().height),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(0.0f, 0.0f,
			bmp->GetSize().width,bmp->GetSize().height)
			
		);

	
}

void SpriteSheet::Draw(int index, int x, int y) {
		
	D2D_RECT_F src = D2D1::RectF(
		static_cast<float>((index % spritesAccross) * spriteWidth),		// claculate position of sprite
		static_cast<float>((index / spritesAccross) * spriteHeight),
		static_cast<float>((index / spritesAccross) * spriteHeight) + spriteWidth,	//calculate size of sprite
		static_cast<float>((index / spritesAccross) * spriteHeight) + spriteHeight
	);
		
	D2D_RECT_F dest = D2D1::RectF(
		x,y,
		x + spriteWidth, y + spriteHeight
	);


	gfx->GetRenderTarget()->DrawBitmap(
		bmp,
		dest,				//destination rectangle
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		src					//source rectangle

	);

}
