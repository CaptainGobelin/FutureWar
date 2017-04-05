#include "../headers/utils/animEffect.h"

AnimEffect::AnimEffect(Effect *effect, bool stackNext) : Animation(0, stackNext) {
	this->effect = effect;
	this->speed = effect->getDuration();
}

AnimEffect::~AnimEffect() {}

void AnimEffect::step() {
	if (over)
		return;
	int k = stepCount*((double)effect->getNFrames()/effect->getDuration());
	Textures::setTile(effect->sprite, effect->getXTile()+k, effect->getYTile());
	if (stepCount >= effect->getDuration()) {
		over = true;
	}
	stepCount++;
}