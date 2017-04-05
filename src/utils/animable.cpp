#include "../headers/utils/animable.h"

Animable::Animable() {
	animations.push_back(this);
}

Animable::~Animable() {
	while (!anim.empty()) {
		delete *anim.begin();
		anim.pop_front();
	}
	animations.remove(this);
}

void Animable::computeAnimations() {
	std::list<Animable*>::iterator it;
	for (it=animations.begin(); it!=animations.end(); ++it) {
		(*it)->step();
	}
}

void Animable::step() {
	if (anim.empty())
		return;
	std::list<Animation*>::iterator it;
	for (it=anim.begin(); it!=anim.end(); it++) {
		(*it)->step();
		if (!(*it)->toStackNext())
			break;
	}
	for (it=anim.begin(); it!=anim.end(); it++) {
		if ((*it)->isOver()) {
			delete *it;
			it = anim.erase(it);
		}
	}
}