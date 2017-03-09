#include "../headers/Model/unit.h"

Unit::Unit(const int *unitInfo, int armyTextureOffset) : Hoverable(UNITS_LAYER, false) {
	this->selected = false;
	sprite = new sf::Sprite();
	sf::Vector2f size(CELL_SIZE, CELL_SIZE);
	setGraphicSize(size);
	unitFactory(unitInfo, armyTextureOffset);
}

Unit::~Unit() {
	delete sprite;
}

void Unit::unitFactory(const int *unitInfo, int armyTextureOffset) {
	speed = unitInfo[2];
	sf::Vector2i offset(CELL_SIZE, CELL_SIZE);
	this->sprite->setTexture(Textures::texturesUnits);
	this->sprite->setTextureRect(sf::IntRect(sf::Vector2i(unitInfo[1]*CELL_SIZE, armyTextureOffset*CELL_SIZE), offset));
}

void Unit::render(Camera *camera) {
	float xPos = this->position.getX()*CELL_SIZE - camera->getPosition().getX();
	float yPos = this->position.getY()*CELL_SIZE - camera->getPosition().getY();
	sf::Vector2f position(xPos, yPos);
	setScreenPosition(position);
	sprite->setPosition(position);
	if (isHover() || isSelected()) {
		sprite->setColor(sf::Color::Green);
	}
	else
		sprite->setColor(sf::Color::White);
	addRender(sprite, false);
}

void Unit::hovered(Point2D p) {}
