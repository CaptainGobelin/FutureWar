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
	sf::Sprite *sprite = new sf::Sprite();
	sprite->setTexture(Textures::texturesMap);
	Textures::setTile(sprite, arrowType, 2);
	sprite->setPosition(computeScreenPosition());
	sprite->setOrigin(SPRITE_SIZE/2, SPRITE_SIZE/2);
	sprite->move(CELL_SIZE/2, CELL_SIZE/2);
	sprite->rotate(getArrowRotation(arrowType, path, nextPath));
	Drawable::addRender(sprite, UNITS_LAYER, true);
}

int Cell::hoverEvent() {
	sf::Vector2f size(CELL_SIZE, CELL_SIZE);
	sf::RectangleShape *rectangle = new sf::RectangleShape(size);
	rectangle->setPosition(computeScreenPosition());
	rectangle->setFillColor(sf::Color(250, 250, 250, 100));
	Drawable::addRender(rectangle, SUB_UNIT_LAYER, true);
	return 0;
}

int Cell::leftClickEvent() {
	return 0;
}

int Cell::getArrowRotation(int arrowType, int path, int nextPath) {
	if (arrowType == 0) {
		if ((path == 0 && nextPath == 2) || (path == 3 && nextPath == 1))
			return 90;
		if ((path == 0 && nextPath == 3) || (path == 2 && nextPath == 1))
			return 180;
		if ((path == 1 && nextPath == 3) || (path == 2 && nextPath == 0))
			return 270;
	}
	else {
		if (path == 0)
			return 180;
		if (path == 2)
			return 270;
		if (path == 3)
			return 90;
	}
	return 0;
}

sf::Vector2f Cell::computeScreenPosition() {
	float xPos = this->position.getX()*CELL_SIZE + parent->getScreenPosition().x;
	float yPos = this->position.getY()*CELL_SIZE + parent->getScreenPosition().y;
	return sf::Vector2f(xPos, yPos);
}