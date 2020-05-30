#include "UserInput.h"

namespace UserInput {
	LPARAM lp;

	


	void SetWindowParams( LPARAM l) {
		lp = l;
	}

	POINT GetCursorPos() {
		POINT p;
		p.x = GET_X_LPARAM(lp);
		p.y = GET_Y_LPARAM(lp);
		return p;
	}

	



	void PlayOnClick() {
		GameController::SwitchLevel(new Level());
		
	}

	void InfoOnClick() {
		GameController::SwitchLevel(new InfoLevel());
	}

	void loadOnClick() {
		//cos
	}

}
