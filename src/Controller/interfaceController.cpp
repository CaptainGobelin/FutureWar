#include "../headers/Controller/interfaceController.h"

InterfaceController::InterfaceController() {
	this->actionMenu = NULL;
	this->font.loadFromFile((std::string)FONT_PATH+"nes.ttf");
}

InterfaceController::~InterfaceController() {
	delete actionMenu;
}

void InterfaceController::openActionMenu() {
	actionMenu = new ActionMenu();
	actionMenu->addButton("Move", &font);
	actionMenu->addButton("Attack", &font);
}

void InterfaceController::closeActionMenu() {
	delete actionMenu;
	actionMenu = NULL;
}

void InterfaceController::render() {
	if (actionMenu != NULL)
		actionMenu->render();
}