#ifndef ANIM_POS_H
#define ANIM_POS_H

#include "../include/const.h"
#include "../include/lib.h"

#include "point2D.h"

class AnimPosition {
	public:
		AnimPosition(Point2D *position, Point2D goalPos);

		const bool &isOver() const {return over;}

		void step();
		
	private:
		Point2D goalPos;
		Point2D *position;
		bool over;
};

#endif