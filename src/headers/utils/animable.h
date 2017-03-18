#ifndef ANIMABLE_H
#define ANIMABLE_H

#include "../include/const.h"
#include "../include/lib.h"

#include "animPosition.h"

class Animable {
	public:
		Animable();
		~Animable();

		virtual bool step();

		static std::list<Animable*> animations;
		static bool computeAnimations();
		
	protected:
		AnimPosition *anim;
};

#endif