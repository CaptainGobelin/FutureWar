#include "../headers/utils/ray.h"

Ray::Ray(double a, Point2D o, int dir) {
	this->a = a;
	this->b = -o.getX()*a;
	this->o = o;
	this->dir = dir;
}

Ray::Ray(double a, double b, Point2D o, int dir) {
	this->a = a;
	this->b = b;
	this->o = o;
	this->dir = dir;
}

double Ray::getIntersectY(double y) {
	if (a == 0)
		return -1;
	return (y-b)/a;
}

double Ray::getIntersectX(double x) {
	return a*x + b;
}