#ifndef MAP_H
#define MAP_H

#include "../include/const.h"
#include "../include/lib.h"

#include "../Controller/interfaceController.h"
#include "../utils/ray.h"
#include "../utils/point2D.h"
#include "../utils/complexShape.h"
#include "../utils/aStarAlgorithm.h"
#include "cell.h"
#include "army.h"

class Map : public Hoverable {
	public:
		Map(InterfaceController *interface, int w=5, int h=5);
		~Map();
		const int &getState() const {return state;}
		void setState(int state) {this->state = state;}
		const int &getHeight() const {return height;}
		const int &getWidth() const {return width;}

		Cell getCell(int x, int y);
		Cell getCell(Point2D p);
		bool isInLimits(Point2D p);
		void render(Camera *camera);

		virtual void hoverEvent(Point2D p);
		virtual void leftClickEvent(Point2D p);
		
		void generateAllMoveList(Army *army);
		void generateMoveList(Unit *unit);
		void generateMovingMask(Unit *unit);

		InterfaceController *interface;
		Cell** cells;
		Unit* selectedUnit;
		void basicMap();
		bool canGo(Unit *u, Point2D p);
		//More complex version but check paths (use wisely)
		int canReach(Unit *u, Cell *c);
		
	private:
		int state;
		int height;
		int width;
		ComplexShape *mapSprite;

		void constructSprite();
		void selectUnit(Unit *unit);
};

#endif