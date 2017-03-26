#include "../headers/utils/animPosition.h"

AnimPosition::AnimPosition(Point2D *position, Point2D goalPos, int speed, bool smooth) {
	this->position = position;
	this->goalPos = goalPos;
	this->over = false;
	this->smooth = smooth;
	this->speed = speed;
}

bool AnimPosition::step() {
	if (over)
		return true;
	if (smooth)
		animSmooth();
	else
		animCut();
	return over;
}

void AnimPosition::animSmooth() {
	double x = (speed*position->getX()+goalPos.getX())/(speed+1);
	double y = (speed*position->getY()+goalPos.getY())/(speed+1);
	if (x == position->getX() && y == position->getY()) {
		over = true;
		x = goalPos.getX();
		y = goalPos.getY();
	}
	position->setX(x);
	position->setY(y);
}

void AnimPosition::animCut() {
	int x = (speed*position->getX()+goalPos.getX())/(speed+1);
	int y = (speed*position->getY()+goalPos.getY())/(speed+1);
	if (x == position->getX() && y == position->getY()) {
		over = true;
		x = goalPos.getX();
		y = goalPos.getY();
	}
	position->setX(x);
	position->setY(y);
}