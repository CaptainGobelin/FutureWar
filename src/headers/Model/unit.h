#ifndef UNIT_H
#define UNIT_H

#include "../include/const.h"
#include "../include/lib.h"

#include "../utils/textures.h"
#include "../utils/camera.h"
#include "../GUI/hoverable.h"
#include "../utils/point2D.h"
#include "cell.h"

class Map;

class Unit : public Hoverable {
	public:
		Unit(const int *unitInfo, int armyTextureOffset, bool playerUnit);
		~Unit();

		const bool &isSelected() const {return selected;}
		void setSelected(bool selected) {this->selected = selected;}
		const int &getSpeed() const {return speed;}
		const int &getRemMov() const {return remMov;}
		const bool &isAvailable() const {return available;}
		const bool &isPlayerUnit() const {return playerUnit;}
		const Point2D &getPosition() const {return position;}
		void setPosition(Point2D position) {this->position = position;}

		void move(Cell *c);
		void newTurn();

		void render(Camera *camera);
		virtual void hoverEvent(Point2D p);
		virtual void leftClickEvent(Point2D p);

		sf::Sprite *sprite;
		std::list<tuple<Cell*, int> > moveReach;
		Cell *cell;
		int remMov;
		
	private:
		bool selected;
		int speed;
		bool available;
		bool playerUnit;
		Point2D position;


		void unitFactory(const int *unitInfo, int armyTextureOffset);
};

#endif
