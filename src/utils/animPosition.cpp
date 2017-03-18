#include "../headers/utils/animPosition.h"

AnimPosition::AnimPosition(Point2D *position, Point2D goalPos, int speed) {
	this->position = position;
	this->goalPos = goalPos;
	this->over = false;
	this->speed = speed;
}

bool AnimPosition::step() {
	if (over)
		return true;
	double x = (speed*position->getX()+goalPos.getX())/(speed+1);
	double y = (speed*position->getY()+goalPos.getY())/(speed+1);
	//std::cout << position->getY() << " " << y << " " << goalPos.getY() << std::endl;
	if (x == position->getX() && y == position->getY()) {
		over = true;
		x = goalPos.getX();
		y = goalPos.getY();
	}
	position->setX(x);
	position->setY(y);
	return over;
}