#include "../headers/Model/cell.h"

Cell::Cell() : HoverableComponent(NULL) {
	this->value = false;
	this->unit = NULL;
}

Cell::Cell(Hoverable* parent) : HoverableComponent(parent) {
	this->value = false;
	this->unit = NULL;
}

void Cell::hoverEvent() {
	float xPos = this->position.getX()*CELL_SIZE + parent->getScreenPosition().x;
	float yPos = this->position.getY()*CELL_SIZE + parent->getScreenPosition().y;
	sf::Vector2f position(xPos, yPos);
	sf::Vector2f size(CELL_SIZE, CELL_SIZE);
	sf::RectangleShape *rectangle = new sf::RectangleShape(size);
	rectangle->setPosition(position);
	rectangle->setFillColor(sf::Color(250, 250, 250, 100));
	Drawable::addRender(rectangle, SUB_UNIT_LAYER, true);
}

void Cell::leftClickEvent() {
	
}