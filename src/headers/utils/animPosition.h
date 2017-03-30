#ifndef ANIM_POS_H
#define ANIM_POS_H

#include "../include/const.h"
#include "../include/lib.h"

#include "animation.h"
#include "point2D.h"

class Camera;

class AnimPosition : public Animation {
	public:
		AnimPosition(Point2D *position, Point2D goalPos, int speed);
		~AnimPosition();

		virtual bool step();
		
	private:
		Point2D startPos;
		Point2D goalPos;
		Point2D *position;
};

#endif