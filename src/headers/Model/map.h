#ifndef MAP_H
#define MAP_H

#include "../include/const.h"
#include "../include/lib.h"

#include "../utils/ray.h"
#include "../utils/point2D.h"
#include "../utils/complexShape.h"
#include "cell.h"

class Map : public Hoverable {
	public:
		Map(int w=5, int h=5);
		~Map();
		const int &getHeight() const {return height;}
		const int &getWidth() const {return width;}

		Cell getCell(int x, int y);
		Cell getCell(Point2D p);
		bool isInLimits(Point2D p);
		void render(Camera *camera);
		virtual void hoverEvent(Point2D p);
		virtual void leftClickEvent(Point2D p);
		void generateMovingMask(Unit *unit, int x, int y);

		Cell** cells;
		Unit* selectedUnit;
		void basicMap();
		bool canGo(Unit u, Point2D p);
		
	private:
		int height;
		int width;
		ComplexShape *mapSprite;

		void constructSprite();
		void selectUnit(Unit *unit);
};

#endif