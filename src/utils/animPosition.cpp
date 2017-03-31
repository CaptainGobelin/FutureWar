#include "../headers/utils/animPosition.h"

AnimPosition::AnimPosition(Point2D *position, Point2D goalPos, int speed) : Animation(speed) {
	this->position = position;
	this->goalPos = goalPos;
	this->startPos = Point2D(*position);
}

AnimPosition::~AnimPosition() {}

bool AnimPosition::step() {
	if (stepCount == 0)
		this->startPos = Point2D(*position);
	if (over)
		return true;
	double k = (double)stepCount/speed;
	double x = (1-k)*startPos.getX() + k*goalPos.getX();
	double y = (1-k)*startPos.getY() + k*goalPos.getY();
	if (stepCount == speed) {
		over = true;
		x = goalPos.getX();
		y = goalPos.getY();
	}
	position->setX(x);
	position->setY(y);
	stepCount++;
	return over;
}