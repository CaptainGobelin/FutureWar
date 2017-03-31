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
	if (anim.empty())
		return true;
	/*std::list<Animation*>::iterator it;
	for (it=anim.begin(); it!=anim.end(); it++) {
		(*it)->step();
		if ((*it)->isOver()) {
			delete *it;
			it = anim.erase(it);
		}
	}*/
	(*anim.begin())->step();
	if ((*anim.begin())->isOver()) {
		delete *anim.begin();
		anim.pop_front();
	}
	return anim.empty();
}