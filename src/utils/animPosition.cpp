#include "../headers/utils/animPosition.h"

AnimPosition::AnimPosition(Point2D *position, Point2D goalPos) {
	this->position = position;
	this->goalPos = goalPos;
	this->over = false;
}

void AnimPosition::step() {
	if (over)
		return;
	int x = (position->getX()+goalPos.getX())/2;
	int y = (position->getY()+goalPos.getY())/2;
	if (x == position->getX() && y == position->getY()) {
		over = true;
		x = goalPos.getX();
		y = goalPos.getY();
	}
	position->setX(x);
	position->setY(y);
}