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
	speed = unitInfo[2] +5;
	range = unitInfo[3];
	this->sprite->setTexture(Textures::texturesUnits);
	Textures::setTile(this->sprite, unitInfo[1], armyTextureOffset);
}

void Unit::move(Cell *c, bool animate) {
	if (cell != NULL)
		cell->unit = NULL;
	c->unit = this;
	position = c->getPosition();
	cell = c;
	if (!animate)
		absolutePos = Point2D::cross(position, CELL_SIZE);
}

void Unit::movementAnimation(Cell *c) {
	anim.push_back(new AnimPosition(&absolutePos, Point2D::cross(c->getPosition(), CELL_SIZE), UNITS_SPEED, false));
}

void Unit::shakingAnimation() {
	anim.push_back(new AnimPosition(&absolutePos, Point2D::substract(absolutePos, 2), UNITS_SPEED/2, false));
	anim.push_back(new AnimPosition(&absolutePos, Point2D::add(absolutePos, 2), UNITS_SPEED/2, false));
	anim.push_back(new AnimPosition(&absolutePos, Point2D::substract(absolutePos, 2), UNITS_SPEED/2, false));
	anim.push_back(new AnimPosition(&absolutePos, absolutePos, UNITS_SPEED/2, false));
}

void Unit::newTurn() {
	remMov = speed;
	available = true;
}

void Unit::attack(Cell *cell) {
	int x = cell->getPosition().getX();
	int y = cell->getPosition().getY();
	new Effect(0, Point2D(x,y));
	if (cell->unit != NULL)
		cell->unit->shakingAnimation();
}

bool Unit::render(Camera *camera) {
	float xPos = this->absolutePos.getX() - camera->getPosition().getX();
	float yPos = this->absolutePos.getY() - camera->getPosition().getY();
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
	return false;
}

void Unit::hoverEvent(Point2D p) {}

void Unit::leftClickEvent(Point2D p) {}