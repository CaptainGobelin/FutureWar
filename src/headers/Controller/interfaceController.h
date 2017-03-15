#ifndef CINTERFACE_H
#define CINTERFACE_H

#include "../include/lib.h"
#include "../include/const.h"

#include "../GUI/actionMenu.h"

class ActionMenu;

class InterfaceController {
	public:
		InterfaceController();
		~InterfaceController();

		const int &getState() const {return state;}
		void setState(int state) {this->state = state;}

		void openActionMenu();
		void deleteActionMenuLink();
		void closeActionMenu();
		void render();

		ActionMenu *actionMenu;
		sf::Font font;

	private:
		int state;
};

#endif