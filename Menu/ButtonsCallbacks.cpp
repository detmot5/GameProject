#include "ButtonsCallbacks.h"

namespace OnClick {


	void PlayOnClick() {
		GameController::SwitchLevel(new Level());

	}

	void InfoOnClick() {
		GameController::SwitchLevel(new InfoLevel());
	}

	void LoadOnClick() {
		cout << "cos";
	}

}
