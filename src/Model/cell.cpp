#include "../headers/Model/cell.h"

Cell::Cell() : HoverableComponent(NULL) {
	this->value = false;
	this->unit = NULL;
}

Cell::Cell(Hoverable* parent) : HoverableComponent(parent) {
	this->value = false;
	this->unit = NULL;
}

void Cell::renderArrow(int path, int nextPath) {
	if (path == -1)
		return;
	int arrowType = 0;
	if (path == nextPath)
		arrowType = 1;
	if (nextPath == -1)
		arrowType = 2;
	float xPos = this->position.getX()*CELL_SIZE + parent->getScreenPosition().x;
	float yPos = this->position.getY()*CELL_SIZE + parent->getScreenPosition().y;
	sf::Vector2f position(xPos, yPos);
	sf::Vector2i offset(CELL_SIZE, CELL_SIZE);
	sf::Sprite *sprite = new sf::Sprite();
	sprite->setTexture(Textures::texturesMap);
	sprite->setTextureRect(sf::IntRect(sf::Vector2i(arrowType*CELL_SIZE, 2*CELL_SIZE), offset));
	sprite->setPosition(position);
	sprite->setOrigin(CELL_SIZE/2, CELL_SIZE/2);
	sprite->move(CELL_SIZE/2, CELL_SIZE/2);
	if (arrowType == 0) {
		if ((path == 0 && nextPath == 2) || (path == 3 && nextPath == 1))
			sprite->rotate(90);
		if ((path == 0 && nextPath == 3) || (path == 2 && nextPath == 1))
			sprite->rotate(180);
		if ((path == 1 && nextPath == 3) || (path == 2 && nextPath == 0))
			sprite->rotate(270);
	}
	else {
		if (path == 0)
			sprite->rotate(180);
		if (path == 2)
			sprite->rotate(270);
		if (path == 3)
			sprite->rotate(90);
	}
	Drawable::addRender(sprite, UNITS_LAYER, true);
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