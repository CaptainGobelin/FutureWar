#include "../headers/utils/animable.h"

Animable::Animable() {
	this->anim = NULL;
	animations.push_back(this);
}

Animable::~Animable() {
	delete anim;
	animations.remove(this);
}

bool Animable::computeAnimations() {
	bool result = false;
	std::list<Animable*>::iterator it;
	for (it=animations.begin(); it!=animations.end(); ++it) {
		bool test = (*it)->step();
		result = result || test;
	}
	return result;
}

bool Animable::step() {
	if (anim == NULL)
		return true;
	anim->step();
	if (anim->isOver()) {
		delete anim;
		anim = NULL;
		return true;
	}
	return false;
}