#include "../headers/utils/aStarNode.h"

AStarNode::AStarNode(Cell *objective, Cell *cell, int cost) {
	this->cell = cell;
	this->cost = cost;
	this->h = cell->getPosition().dist(objective->getPosition());
	this->path = -1;
	this->previous = NULL;
}

AStarNode::AStarNode(Cell *cell, int cost, int h) {
	this->cell = cell;
	this->cost = cost;
	this->h = h;
	this->path = -1;
	this->previous = NULL;
}