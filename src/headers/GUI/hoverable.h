#ifndef HOVERABLE_H
#define HOVERABLE_H

#include "../include/const.h"
#include "../include/lib.h"

#include "drawable.h"

class Hoverable : public Drawable {
	public:
		Hoverable(int layer, bool stopRay);
		virtual ~Hoverable();

		const bool &isHover() const {return hover;}
		void setHover(bool hover) {this->hover = hover;}

		virtual void hoverEvent(Point2D p = Point2D(0,0)) = 0;
		virtual void leftClickEvent(Point2D p = Point2D(0,0)) = 0;

		static std::list<Hoverable*> hoverableElements;
		static void refreshHoverStates();
		static void checkHoverEvents(sf::Vector2i cursor);

	protected:
		bool hover;
		bool stopRay;
};

#endif
