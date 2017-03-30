#include "../headers/utils/animation.h"

Animation::Animation(int speed) {
	this->over = false;
	this->speed = speed;
	this->stepCount = 0;
}

Animation::~Animation() {}