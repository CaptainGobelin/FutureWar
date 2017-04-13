#include "../headers/utils/animOpacity.h"

AnimOpacity::AnimOpacity(sf::Text *text, sf::Uint8 goal, int speed, bool stackNext)
		: Animation(speed, stackNext) {
	this->text = text;
	this->goal = goal;
	this->start = text->getColor().a;
}

AnimOpacity::~AnimOpacity() {}

void AnimOpacity::step() {
	if (over)
		return;
	if (stepCount == 0)
		this->start = text->getColor().a;
	double k = (double)stepCount/speed;
	double x = (1-k)*start + k*goal;
	if (stepCount == speed) {
		over = true;
		x = goal;
	}
	text->setColor(sf::Color(255,255,255, x));
	stepCount++;
}