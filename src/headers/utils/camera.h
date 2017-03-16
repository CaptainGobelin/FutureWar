#ifndef CAMERA_H
#define CAMERA_H

#include "../include/const.h"
#include "../include/lib.h"

#include "point2D.h"

class Camera {
	public:
		Camera();
		Camera(Point2D position);

		const Point2D &getPosition() const {return position;}

		bool move(Point2D offset);
		void step();
		
	private:
		Point2D position;
		Point2D goalPos;
};

#endif