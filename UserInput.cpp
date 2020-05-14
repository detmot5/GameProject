#include "UserInput.h"

namespace UserInput {
	POINT crs;
	WPARAM butt;
	void PlayOnClick() {
		GameController::SwitchLevel(new Level());
	}

	void InfoOnClick() {
		cout << "Czes pomyliles sie";
	}

}
