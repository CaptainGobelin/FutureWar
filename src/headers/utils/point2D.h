#ifndef POINT_H
#define POINT_H

#include "../include/const.h"
#include "../include/lib.h"

class Point2D {
	public:
		Point2D(double x=0, double y=0);
		Point2D(sf::Vector2i v);
		void setX(double x) {this->x = x;}
		const double &getX() const {return x;}
		void setY(double y) {this->y = y;}
		const double &getY() const {return y;}

		void add(Point2D offset);
		static Point2D add(Point2D p1, Point2D p2);
		void substract(Point2D offset);
		static Point2D substract(Point2D p1, Point2D p2);
		void cross(int n);
		static Point2D cross(Point2D p, int n);
		void divide(int n);
		static Point2D divide(Point2D p, int n);
		int dist(const Point2D p) const;
		
	private:
		double x;
		double y;
};

#endif