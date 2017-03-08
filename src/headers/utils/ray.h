#ifndef RAY_H
#define RAY_H

#include "../include/const.h"
#include "../include/lib.h"

#include "point2D.h"

class Ray {
	public:
		Ray(double a, Point2D o, int dir);
		Ray(double a, double b, Point2D o, int dir);
		Point2D o;
		/*const double &getA() const {return a;}
		const double &getB() const {return b;}*/

		double getIntersectY(double y);
		double getIntersectX(double x);
		
	private:
		double a;
		double b;
		//dir: -1 = up, 1 = down
		int dir;
};

#endif