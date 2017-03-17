#include "../headers/utils/animable.h"

Animable::Animable() {
	this->anim = NULL;
	animations.push_back(this);
}

Animable::~Animable() {
	delete anim;
	animations.remove(this);
}

void Animable::computeAnimations() {
	std::list<Animable*>::iterator it;
	for (it=animations.begin(); it!=animations.end(); ++it) {
		(*it)->step();
	}
}

void Animable::step() {
	if (anim == NULL)
		return;
	anim->step();
	if (anim->isOver()) {
		delete anim;
		anim = NULL;
	}
}