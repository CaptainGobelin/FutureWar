#include "../headers/utils/camera.h"

Camera::Camera() {
	Point2D origin = Point2D(0,0);
	this->position = position;
}

Camera::Camera(Point2D position) {
	this->position = position;
}

bool Camera::move(Point2D offset) {
	//TODO check collision
	goalPos.add(offset);
	return true;
}

void Camera::step() {
	int x = (position.getX()+goalPos.getX())/2;
	int y = (position.getY()+goalPos.getY())/2;
	position.setX(x);
	position.setY(y);
}