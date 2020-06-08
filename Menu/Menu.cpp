#include "Menu.h"
#include "../GameController.h"


Menu::Menu() {
	this->gfx = gfx;
	backGroundMenu = 0;
	buttonPlay = 0;
	buttonPlayDark = 0;
	buttonInfo = 0;
	buttonInfoDark = 0;
	buttonPlayDark = 0;
	buttonLoad = 0;
	buttonLoadDark = 0;
}

Menu::~Menu() {
	this->Unload();
	
}


void Menu::Load() {
	backGroundMenu = new Background(Path::background, gfx);

	buttonPlay = new ButtonMenu(Path::buttonPlay, Path::buttonPlayClicked, gfx, 230, OnClick::PlayOnClick);

	buttonLoad = new ButtonMenu(Path::buttonLoad, Path::buttonLoadClicked, gfx, 120, OnClick::LoadOnClick);

	buttonInfo = new ButtonMenu(Path::buttonInfo, Path::buttonInfoClicked, gfx, 10, OnClick::InfoOnClick);


}


void Menu::Unload() 
{
	delete backGroundMenu;
	delete buttonPlay;
	delete buttonLoad;
	delete buttonInfo;
	
	

}


void Menu::Update() 
{
	buttonPlay->OnClickEvent();
	buttonInfo->OnClickEvent();
	buttonLoad->OnClickEvent();
}


void Menu::Render() {
	gfx->ClearScreen(0, 0, 0);
	backGroundMenu->Render();

	buttonPlay->Render();


	buttonInfo->Render();


	buttonLoad->Render();
	
}



