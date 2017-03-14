#ifndef ACTION_MENU_H
#define ACTION_MENU_H

#include "../include/lib.h"
#include "../include/const.h"

#include "actionMenuButton.h"

class ActionMenu : public Hoverable {
	public:
		ActionMenu();
		~ActionMenu();

		virtual void hoverEvent(Point2D p);
		virtual void leftClickEvent(Point2D p);

		void addButton(std::string name, sf::Font *font);
		void render();

		std::vector<ActionMenuButton*> buttons;

	private:
};

#endif