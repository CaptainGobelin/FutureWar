#ifndef ANIMATION_H
#define ANIMATION_H

#include "../include/const.h"
#include "../include/lib.h"

class Animation {
	public:
		Animation(int speed, bool stackNext);
		virtual ~Animation();
		const bool &isOver() const {return over;}
		const bool &toStackNext() const {return stackNext;}
		void cut();

		virtual void step() = 0;
		
	protected:
		bool over;
		int speed;
		int stepCount;
		bool stackNext;
};

#endif