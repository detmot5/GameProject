#include "ButtonsCallbacks.h"

namespace OnClick {


	void PlayOnClick() {

		GameController::SwitchLevel(new Level(Level::NewSave));

	}

	void InfoOnClick() {
		GameController::SwitchLevel(new InfoLevel());
	}

	void LoadOnClick() {
		GameController::SwitchLevel(new MenuLoad());
	}

}
