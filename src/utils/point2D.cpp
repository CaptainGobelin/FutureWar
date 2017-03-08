#include "../headers/utils/point2D.h"

Point2D::Point2D(double x, double y) {
	this->x = x;
	this->y = y;
}

Point2D::Point2D(sf::Vector2i v) {
	this->x = v.x;
	this->y = v.y;
}

void Point2D::add(Point2D offset) {
	this->x += offset.getX();
	this->y += offset.getY();
}

Point2D Point2D::add(Point2D p1, Point2D p2) {
	Point2D result = p1;
	result.add(p2);
	return result;
}

void Point2D::substract(Point2D offset) {
	this->x -= offset.getX();
	this->y -= offset.getY();
}

Point2D Point2D::substract(Point2D p1, Point2D p2) {
	Point2D result = p1;
	result.substract(p2);
	return result;
}

void Point2D::divide(int n) {
	this->x /= n;
	this->y /= n;
}

Point2D Point2D::divide(Point2D p, int n) {
	Point2D result = p;
	result.divide(n);
	return result;
}

int Point2D::dist(Point2D p) {
	return abs(p.getX()-x) + abs(p.getY()-y);
}