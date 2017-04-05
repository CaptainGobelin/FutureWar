#ifndef ANIMABLE_H
#define ANIMABLE_H

#include "../include/const.h"
#include "../include/lib.h"

#include "animation.h"

class Animable {
	public:
		Animable();
		~Animable();

		virtual void step();

		static std::list<Animable*> animations;
		static void computeAnimations();
		
	protected:
		std::list<Animation*> anim;
};

#endif