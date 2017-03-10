#ifndef POINT_H
#define POINT_H

#include "../include/const.h"
#include "../include/lib.h"

class Point2D {
	public:
		Point2D(double x=0, double y=0);
		Point2D(sf::Vector2i v);
		const double &getX() const {return x;}
		const double &getY() const {return y;}

		void add(Point2D offset);
		static Point2D add(Point2D p1, Point2D p2);
		void substract(Point2D offset);
		static Point2D substract(Point2D p1, Point2D p2);
		void divide(int n);
		static Point2D divide(Point2D p, int n);
		int dist(const Point2D p) const;
		
	private:
		double x;
		double y;
};

#endif