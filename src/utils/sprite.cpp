#include "../headers/utils/sprite.h"

Sprite::Sprite(sf::Text* graphic, Point2D position, int layer) : Drawable(layer) {
	this->graphic = graphic;
	this->position = position;
}

Sprite::~Sprite() {
	delete graphic;
}

bool Sprite::render(Camera *camera) {
	float xPos = this->position.getX()*CELL_SIZE - camera->getPosition().getX();
	float yPos = this->position.getY()*CELL_SIZE - camera->getPosition().getY();
	sf::Vector2f position(xPos, yPos);
	setScreenPosition(position);
	graphic->setPosition(position);
	if (anim.empty()) {
		toDestroy = true;
		return true;
	}
	addRender(graphic, false);
	return false;
}