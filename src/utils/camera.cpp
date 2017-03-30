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
	if (anim.empty())
		anim.push_back(new AnimPosition(&position, Point2D::add(position, offset), CAMERA_SPEED));
	return true;
}