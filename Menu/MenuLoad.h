#pragma once
#include <vector>
#include <chrono>
#include "../framework.h"
#include "../Level.h"
#include "../GameSaver/GameSaver.h"
#include "ButtonPaperSheet.h"
#include "BackgroundMenu.h"
#include "UserInput.h"
#include "../GameController.h"
class MenuLoad : public GameLevel
{


public:
	MenuLoad();
	~MenuLoad();


	void Load() override;
	void Unload() override;
	void Update() override;
	void Render() override;




private:
	Background* background;
	vector<ButtonPaperSheet*> sheets;
	vector<wstring> saves;
	static void LoadLevel(const WCHAR* path);


};

