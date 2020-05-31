#pragma once
#include <windowsx.h>
#include "../framework.h"
#include "../GameController.h"
#include "../Level.h"
#include "InfoLevel.h"

#include "ButtonMenu.h"

namespace UserInput {

	void SetWindowParams(LPARAM l);
	POINT GetCursorPos();
	void PlayOnClick();
	void InfoOnClick();
	void LoadOnClick();
};