#include "../headers/GUI/hoverableComponent.h"

HoverableComponent::HoverableComponent(Hoverable* parent) {
	this->hover = false;
	this->parent = parent;
}