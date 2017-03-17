#ifndef ANIMABLE_H
#define ANIMABLE_H

#include "../include/const.h"
#include "../include/lib.h"

#include "animPosition.h"

class Animable {
	public:
		Animable();
		~Animable();

		virtual void step();

		static std::list<Animable*> animations;
		static void computeAnimations();
		
	protected:
		AnimPosition *anim;
};

#endif