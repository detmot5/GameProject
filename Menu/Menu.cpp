#include "Menu.h"
#include "../GameController.h"


Menu::Menu() {
	this->gfx = gfx;
	backGroundMenu = 0;
	buttonPlay = 0;
	buttonPlayDark = 0;
	buttonInfo = 0;
	buttonPlayDark = 0;
	buttonLoad = 0;
	buttonLoadDark = 0;
}


void Menu::Load() {
	backGroundMenu = new Background(L"GameProject/Graphicss/BackgroundMenuTree.png", gfx);

	buttonPlay = new ButtonMenu(L"GameProject/Graphicss/ButtonPlay.png", gfx, 200, OnClick::PlayOnClick);
	buttonPlayDark = new ButtonMenu(L"GameProject/Graphicss/ButtonPlayW.png", gfx, 200, OnClick::PlayOnClick);

	buttonLoad = new ButtonMenu(L"GameProject/Graphicss/ButtonLoad.png", gfx, 110, OnClick::LoadOnClick);
	buttonLoadDark = new ButtonMenu(L"GameProject/Graphicss/ButtonLoadW.png", gfx, 110, OnClick::LoadOnClick);

	buttonInfo = new ButtonMenu(L"GameProject/Graphicss/ButtonInfo.png", gfx, 20, OnClick::InfoOnClick);
	buttonInfoDark = new ButtonMenu(L"GameProject/Graphicss/ButtonInfoW.png", gfx, 20, OnClick::InfoOnClick);

}


void Menu::Unload() 
{
	delete backGroundMenu;
	delete buttonPlay;
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

	if (ButtonMenu::flag == 1)
	{
		buttonPlayDark->Render();
	}
	else if (ButtonMenu::flag == 2) 
	{
		buttonLoadDark->Render();
	}
	else if (ButtonMenu::flag == 3)
	{
		buttonInfoDark->Render();
	}

	
}



