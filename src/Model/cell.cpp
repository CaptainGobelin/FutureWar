#include "../headers/Model/cell.h"

Cell::Cell() {
	this->value = false;
	this->unit = NULL;
}

void Cell::hovered(sf::Vector2f cameraOffset) {
	float xPos = this->position.getX()*CELL_SIZE + cameraOffset.x;
	float yPos = this->position.getY()*CELL_SIZE + cameraOffset.y;
	sf::Vector2f position(xPos, yPos);
	sf::Vector2f size(CELL_SIZE, CELL_SIZE);
	sf::RectangleShape *rectangle = new sf::RectangleShape(size);
	rectangle->setPosition(position);
	rectangle->setFillColor(sf::Color(250, 250, 250, 100));
	Drawable::addRender(rectangle, SUB_UNIT_LAYER, true);
}