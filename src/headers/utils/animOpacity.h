#ifndef ANIM_OPACITY_H
#define ANIM_OPACITY_H

#include "../include/const.h"
#include "../include/lib.h"

#include "../GUI/drawable.h"
#include "animation.h"

class AnimOpacity : public Animation {
	public:
		AnimOpacity(sf::Text *text, sf::Uint8 goal, int speed, bool stackNext);
		~AnimOpacity();

		virtual void step();
		
	private:
		sf::Uint8 start;
		sf::Uint8 goal;
		sf::Text *text;

};

#endif