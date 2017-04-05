#include "../headers/utils/destroyable.h"

Destroyable::Destroyable() {
	this->toDestroy = false;
	destroyables.push_back(this);
}

Destroyable::~Destroyable() {
}

void Destroyable::cleanDestroyables() {
	std::list<Destroyable*>::iterator it;
	for (it=destroyables.begin(); it!=destroyables.end(); it++) {
		if ((*it)->toDestroy) {
			delete *it;
			it = destroyables.erase(it);
		}
	}
}