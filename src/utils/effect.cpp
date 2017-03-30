#include "../headers/utils/effect.h"

Effect::Effect() : Drawable(EFFECTS_LAYER) {}

Effect::Effect(int effectInfo, Point2D position) : Drawable(EFFECTS_LAYER) {
	this->position = position;
	sprite = new sf::Sprite();
	effectFactory(effectInfo);
	anim.push_back(new AnimEffect(this));
}

Effect::~Effect() {
	delete sprite;
}

void Effect::effectFactory(int effectInfo) {
	duration = effects[effectInfo][3];
	nFrames = effects[effectInfo][2];
	xTile = effects[effectInfo][0];
	yTile = effects[effectInfo][1];
	this->sprite->setTexture(Textures::texturesEffects);
	Textures::setTile(this->sprite, xTile, yTile);
}

void Effect::render(Camera *camera) {
	if (anim.empty()) {
		delete this;
		return;
	}
	float xPos = this->position.getX()*CELL_SIZE - camera->getPosition().getX();
	float yPos = this->position.getY()*CELL_SIZE - camera->getPosition().getY();
	sf::Vector2f position(xPos, yPos);
	setScreenPosition(position);
	sprite->setPosition(position);
	addRender(sprite, false);
}