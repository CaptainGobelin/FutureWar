#include "../headers/utils/animEffect.h"

AnimEffect::AnimEffect(Effect *effect) : Animation(0) {
	this->effect = effect;
	this->speed = effect->getDuration();
}

AnimEffect::~AnimEffect() {}

bool AnimEffect::step() {
	if (over)
		return true;
	int k = stepCount*((double)effect->getNFrames()/effect->getDuration());
	Textures::setTile(effect->sprite, effect->getXTile()+k, effect->getYTile());
	if (stepCount >= effect->getDuration()) {
		over = true;
	}
	stepCount++;
	return over;
}