#ifndef CELL_H
#define CELL_H

#include "../include/const.h"
#include "../include/lib.h"

#include "../GUI/hoverableComponent.h"
#include "../utils/camera.h"
#include "map.h"

class Unit;
class Map;

class Cell : public HoverableComponent {
	public:
		Cell();
		Cell(Map* map, Hoverable* parent);

		const bool &getValue() const {return value;}
		void setValue(bool value) {this->value = value;}
		const Point2D &getPosition() const {return position;}
		void setPosition(Point2D position) {this->position = position;}

		void renderArrow(int path, int nextPath);

		virtual int hoverEvent();
		virtual int leftClickEvent();

		Unit* unit;
		Map* map;
		
	private:
		bool value;
		Point2D position;

		int getArrowRotation(int arrowType, int path, int nextPath);
		sf::Vector2f computeScreenPosition();
};

#endif