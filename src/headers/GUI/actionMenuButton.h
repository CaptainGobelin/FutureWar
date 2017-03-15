#ifndef ACTION_MENU_BUTTON_H
#define ACTION_MENU_BUTTON_H

#include "../include/lib.h"
#include "../include/const.h"

#include "menuStates.h"
#include "hoverableComponent.h"

class ActionMenuButton : public HoverableComponent {
	public:
		ActionMenuButton(Hoverable* parent, std::string name, int yOffset, sf::Font *font);
		~ActionMenuButton();

		void render();

		virtual int hoverEvent();
		virtual int leftClickEvent();

		sf::Sprite *sprite[2];
		sf::Text *text;


	private:
		sf::Font *font;
		std::string name;
};

#endif