#ifndef SPRITE_H
#define SPRITE_H

#include "../include/const.h"
#include "../include/lib.h"

#include "point2D.h"
#include "destroyable.h"
#include "../GUI/drawable.h"
#include "animable.h"

class Sprite : public Drawable, public Animable, public Destroyable {
	public:
		Sprite(sf::Text* graphic, Point2D position, int layer);
		~Sprite();

		virtual bool render(Camera *camera);

		Point2D position;

	private:
		sf::Text* graphic;
		
};

#endif
