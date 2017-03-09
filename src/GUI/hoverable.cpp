#include "../headers/GUI/hoverable.h"

Hoverable::Hoverable(int layer, bool stopRay) : Drawable(layer) {
	this->stopRay = stopRay;
	this->hover = false;
	std::list<Hoverable*>::iterator it;
	for (it=hoverableElements.begin(); it!=hoverableElements.end(); it++) {
		if ((*it)->getLayer() < this->getLayer()) {
			hoverableElements.insert(it, this);
			return;
		}
	}
	Hoverable::hoverableElements.push_back(this);
}

Hoverable::~Hoverable() {
	hoverableElements.remove(this);
}

void Hoverable::refreshHoverStates() {
	std::list<Hoverable*>::iterator it;
	for (it=hoverableElements.begin(); it!=hoverableElements.end(); ++it) {
		(*it)->setHover(false);
	}
}

void Hoverable::checkHoverEvents(sf::Vector2i cursor) {
	refreshHoverStates();
	std::list<Hoverable*>::iterator it;
	for (it=hoverableElements.begin(); it!=hoverableElements.end(); ++it) {
		if ((*it)->isInLimits(cursor)) {
			(*it)->hover = true;
			(*it)->hoverEvent(Point2D::divide(Point2D(cursor), CELL_SIZE));
			if ((*it)->stopRay)
				return;
		}
	}
}
