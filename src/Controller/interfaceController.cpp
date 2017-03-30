#include "../headers/Controller/interfaceController.h"

InterfaceController::InterfaceController() {
	this->state = NORMAL_STATE;
	this->actionMenu = NULL;
	this->font.loadFromFile((std::string)FONT_PATH+"nes.ttf");
}

InterfaceController::~InterfaceController() {
	delete actionMenu;
}

void InterfaceController::openActionMenu() {
	actionMenu = new ActionMenu(this);
	actionMenu->addButton("Move", &font);
	actionMenu->addButton("Attack", &font);
	state = NORMAL_STATE;
}

void InterfaceController::deleteActionMenuLink() {
	actionMenu = NULL;
}

void InterfaceController::closeActionMenu() {
	delete actionMenu;
	deleteActionMenuLink();
}