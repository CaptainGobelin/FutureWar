#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "../include/const.h"
#include "../include/lib.h"

#include "gameWindow.h"
#include "../utils/textures.h"
#include "../utils/camera.h"
#include "../utils/point2D.h"

using boost::tuple;

class Drawable {
	public:
		Drawable(int layer);
		~Drawable();

		const int &getLayer() const {return layer;}
		void setScreenPosition(sf::Vector2f screenPosition) {this->screenPosition = screenPosition;}
		void setGraphicSize(sf::Vector2f graphicSize) {this->graphicSize = graphicSize;}

		void addRender();

		static std::list<tuple<sf::Drawable*, int, bool> > renderQueue;
		static void renderAll();
		static void addRender(sf::Drawable* graphic, int layer, bool ephemeral);

	protected:
		int layer;
		sf::Vector2f screenPosition;
		sf::Vector2f graphicSize;

		bool isInLimits(sf::Vector2i cursor);
		void addRender(sf::Drawable* graphic, bool ephemeral);
};

#endif
