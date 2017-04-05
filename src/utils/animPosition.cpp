#include "../headers/utils/animPosition.h"

AnimPosition::AnimPosition(Point2D *position, Point2D goalPos, int speed, bool stackNext)
		: Animation(speed, stackNext) {
	this->position = position;
	this->goalPos = goalPos;
	this->startPos = Point2D(*position);
}

AnimPosition::~AnimPosition() {}

void AnimPosition::step() {
	if (over)
		return;
	if (stepCount == 0)
		this->startPos = Point2D(*position);
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
}