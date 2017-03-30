#include "../headers/GUI/drawable.h"

Drawable::Drawable(int layer) {
	this->layer = layer;
	Drawable::drawableElements.push_back(this);
}

Drawable::~Drawable() {
	drawableElements.remove(this);
}

void Drawable::renderAll(Camera *camera) {
	std::list<Drawable*>::iterator it;
	for (it=drawableElements.begin(); it!=drawableElements.end(); ++it) {
		(*it)->render(camera);
	}
}

void Drawable::renderDrawQueue() {
	while (!renderQueue.empty()) {
		GameWindow::window.draw(*renderQueue.begin()->get<0>());
		if (renderQueue.begin()->get<2>())
			delete renderQueue.begin()->get<0>();
		renderQueue.pop_front();
	}
}

bool Drawable::isInLimits(sf::Vector2i cursor) {
	if (cursor.x < screenPosition.x)
		return false;
	if (cursor.y < screenPosition.y)
		return false;
	if (cursor.x >= (screenPosition.x+graphicSize.x))
		return false;
	if (cursor.y >= (screenPosition.y+graphicSize.y))
		return false;
	return true;
}

void Drawable::addRender(sf::Drawable* graphic, int layer, bool ephemeral) {
	std::list<tuple<sf::Drawable*, int, bool> >::iterator it;
	for (it=renderQueue.begin(); it!=renderQueue.end(); it++) {
		if ((it)->get<1>() >= layer) {
			renderQueue.insert(it, tuple<sf::Drawable*, int, bool>(graphic, layer, ephemeral));
			return;
		}
	}
	renderQueue.push_back(tuple<sf::Drawable*, int, bool>(graphic, layer, ephemeral));
}

void Drawable::addRender(sf::Drawable* graphic, bool ephemeral) {
	addRender(graphic, this->getLayer(), ephemeral);
}