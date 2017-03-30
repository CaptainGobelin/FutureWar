#ifndef ANIMABLE_H
#define ANIMABLE_H

#include "../include/const.h"
#include "../include/lib.h"

#include "animation.h"

class Animable {
	public:
		Animable();
		~Animable();

		virtual bool step();

		static std::list<Animable*> animations;
		static bool computeAnimations();
		
	protected:
		std::list<Animation*> anim;
};

#endif