#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "../include/const.h"
#include "../include/lib.h"

#include "gameWindow.h"
#include "../utils/textures.h"
#include "../utils/point2D.h"
#include "../utils/camera.h"

using boost::tuple;

class Drawable {
	public:
		Drawable(int layer);
		virtual ~Drawable();

		const int &getLayer() const {return layer;}
		const sf::Vector2f getScreenPosition() const {return screenPosition;}
		void setScreenPosition(sf::Vector2f screenPosition) {this->screenPosition = screenPosition;}
		const sf::Vector2f getGraphicSize() const {return graphicSize;}
		void setGraphicSize(sf::Vector2f graphicSize) {this->graphicSize = graphicSize;}

		void addRender();
		virtual bool render(Camera *camera) = 0;

		static std::list<Drawable*> drawableElements;
		static std::list<tuple<sf::Drawable*, int, bool> > renderQueue;
		static void renderAll(Camera *camera);
		static void renderDrawQueue();
		static void addRender(sf::Drawable* graphic, int layer, bool ephemeral);

	protected:
		int layer;
		sf::Vector2f screenPosition;
		sf::Vector2f graphicSize;

		bool isInLimits(sf::Vector2i cursor);
		void addRender(sf::Drawable* graphic, bool ephemeral);
};

#endif
