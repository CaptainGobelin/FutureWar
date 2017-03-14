#ifndef CINTERFACE_H
#define CINTERFACE_H

#include "../include/lib.h"
#include "../include/const.h"

#include "../GUI/actionMenu.h"

class InterfaceController {
	public:
		InterfaceController();
		~InterfaceController();

		void openActionMenu();
		void closeActionMenu();
		void render();

		ActionMenu *actionMenu;
		sf::Font font;

	private:
};

#endif