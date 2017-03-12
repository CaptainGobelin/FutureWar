#ifndef CELL_H
#define CELL_H

#include "../include/const.h"
#include "../include/lib.h"

#include "unit.h"
#include "../GUI/hoverableComponent.h"
#include "../utils/camera.h"

class Cell : public HoverableComponent {
	public:
		Cell();
		Cell(Hoverable* parent);

		const bool &getValue() const {return value;}
		void setValue(bool value) {this->value = value;}
		void setUnit(Unit* unit) {this->unit = unit;unit->setPosition(position);}
		const Point2D &getPosition() const {return position;}
		void setPosition(Point2D position) {this->position = position;}

		void renderArrow(int path, int nextPath);

		virtual void hoverEvent();
		virtual void leftClickEvent();

		Unit* unit;
		
	private:
		bool value;
		Point2D position;

		int getArrowRotation(int arrowType, int path, int nextPath);
		sf::Vector2f computeScreenPosition();
};

#endif