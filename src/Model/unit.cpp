#include "../headers/Model/unit.h"

Unit::Unit(const int *unitInfo, int armyTextureOffset, bool playerUnit) : Hoverable(UNITS_LAYER, false) {
	this->selected = false;
	this->cell = NULL;
	this->playerUnit = playerUnit;
	moveReach.clear();
	sprite = new sf::Sprite();
	sf::Vector2f size(CELL_SIZE, CELL_SIZE);
	setGraphicSize(size);
	unitFactory(unitInfo, armyTextureOffset);
	newTurn();
}

Unit::~Unit() {
	delete sprite;
}

void Unit::unitFactory(const int *unitInfo, int armyTextureOffset) {
	speed = unitInfo[2];
	range = unitInfo[3];
	this->sprite->setTexture(Textures::texturesUnits);
	Textures::setTile(this->sprite, unitInfo[1], armyTextureOffset);
}

void Unit::move(Cell *c) {
	if (cell != NULL)
		cell->unit = NULL;
	c->unit = this;
	position = c->getPosition();
	cell = c;
}

void Unit::newTurn() {
	remMov = speed;
	available = true;
}

void Unit::render(Camera *camera) {
	float xPos = this->position.getX()*CELL_SIZE - camera->getPosition().getX();
	float yPos = this->position.getY()*CELL_SIZE - camera->getPosition().getY();
	sf::Vector2f position(xPos, yPos);
	setScreenPosition(position);
	sprite->setPosition(position);
	if (!isAvailable()) {
		sprite->setColor(sf::Color(100, 100, 100));
	}
	else if (isHover() || isSelected()) {
		sprite->setColor(sf::Color::Green);
	}
	else
		sprite->setColor(sf::Color::White);
	addRender(sprite, false);
}

void Unit::hoverEvent(Point2D p) {}

void Unit::leftClickEvent(Point2D p) {}