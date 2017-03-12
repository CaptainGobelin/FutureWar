#include "../headers/Model/unit.h"

Unit::Unit(const int *unitInfo, int armyTextureOffset) : Hoverable(UNITS_LAYER, false) {
	this->selected = false;
	moveReach.clear();
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
	this->sprite->setTexture(Textures::texturesUnits);
	Textures::setTile(this->sprite, unitInfo[1], armyTextureOffset);
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

void Unit::hoverEvent(Point2D p) {}

void Unit::leftClickEvent(Point2D p) {}