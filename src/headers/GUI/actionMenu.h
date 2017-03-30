#ifndef ACTION_MENU_H
#define ACTION_MENU_H

#include "../include/lib.h"
#include "../include/const.h"

#include "actionMenuButton.h"
#include "../Controller/interfaceController.h"
#include "../utils/camera.h"

class InterfaceController;

class ActionMenu : public Hoverable {
	public:
		ActionMenu(InterfaceController *interface);
		~ActionMenu();

		virtual void hoverEvent(Point2D p);
		virtual void leftClickEvent(Point2D p);

		void addButton(std::string name, sf::Font *font);
		virtual bool render(Camera* camera);

		std::vector<ActionMenuButton*> buttons;
		InterfaceController *interface;

	private:
};

#endif