#ifndef ANIMATION_H
#define ANIMATION_H

#include "../include/const.h"
#include "../include/lib.h"

class Animation {
	public:
		Animation(int speed);
		virtual ~Animation();
		const bool &isOver() const {return over;}

		virtual bool step() = 0;
		
	protected:
		bool over;
		int speed;
		int stepCount;
};

#endif