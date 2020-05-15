#include "UserInput.h"

namespace UserInput {
	WPARAM wp;
	LPARAM lp;

	


	void SetWindowParams(WPARAM w, LPARAM l) {
		wp = l;
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
		cout << "Czes pomyliles sie";
	}

}
