#ifndef CAMERA_H
#define CAMERA_H

#include "../include/const.h"
#include "../include/lib.h"

#include "point2D.h"
#include "animable.h"
#include "animPosition.h"

class Camera : public Animable {
	public:
		Camera();
		Camera(Point2D position);

		const Point2D &getPosition() const {return position;}

		bool move(Point2D offset);
		
		
	private:
		Point2D position;
};

#endif