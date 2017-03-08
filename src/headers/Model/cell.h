#ifndef CELL_H
#define CELL_H

#include "../include/const.h"
#include "../include/lib.h"

#include "unit.h"
#include "../GUI/hoverable.h"
#include "../utils/camera.h"

class Cell {
	public:
		Cell();

		const bool &getValue() const {return value;}
		void setValue(bool value) {this->value = value;}
		void setUnit(Unit* unit) {this->unit = unit;unit->setPosition(position);}
		void setPosition(Point2D position) {this->position = position;}

		void hovered(sf::Vector2f cameraOffset);

		Unit* unit;
		
	private:
		bool value;
		Point2D position;
};

#endif