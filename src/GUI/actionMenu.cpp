#include "../headers/GUI/actionMenu.h"

ActionMenu::ActionMenu(InterfaceController *interface) : Hoverable(INTERFACE_LAYER, true) {
	this->interface = interface;
	buttons.clear();
	setScreenPosition(sf::Vector2f(2*CELL_SIZE, 2*CELL_SIZE));
	setGraphicSize(sf::Vector2f(4*CELL_SIZE, buttons.size()*CELL_SIZE));
}

ActionMenu::~ActionMenu() {
	for (int i=0;i<buttons.size();i++)
		delete buttons[i];
}

void ActionMenu::addButton(std::string name, sf::Font *font) {
	ActionMenuButton *button = new ActionMenuButton(this, name, buttons.size(), font);
	buttons.push_back(button);
	setGraphicSize(sf::Vector2f(4*CELL_SIZE, buttons.size()*CELL_SIZE));
}

void ActionMenu::render(Camera* camera) {
	for (int i=0;i<buttons.size();i++)
		buttons[i]->render();
}

void ActionMenu::hoverEvent(Point2D p) {
	int yOffset = (int)(p.getY() - screenPosition.y/CELL_SIZE);
	buttons[yOffset]->hoverEvent();
}

void ActionMenu::leftClickEvent(Point2D p) {
	int yOffset = (int)(p.getY() - screenPosition.y/CELL_SIZE);
	interface->setState(buttons[yOffset]->leftClickEvent());
	interface->deleteActionMenuLink();
	delete this;
}