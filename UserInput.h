#pragma once
#include <windowsx.h>
#include "framework.h"
#include "GameController.h"
#include "Level.h"

namespace UserInput {

	void SetWindowParams(WPARAM w, LPARAM l);
	POINT GetCursorPos();
	void PlayOnClick();
	void InfoOnClick();

};