#include "../headers/utils/animation.h"

Animation::Animation(int speed, bool stackNext) {
	this->over = false;
	this->speed = speed;
	this->stepCount = 0;
	this->stackNext = stackNext;
}

Animation::~Animation() {}

void Animation::cut() {
	stepCount = speed;
}