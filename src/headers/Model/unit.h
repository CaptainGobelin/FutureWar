#ifndef UNIT_H
#define UNIT_H

#include "../include/const.h"
#include "../include/lib.h"

#include "../utils/textures.h"
#include "../utils/camera.h"
#include "../GUI/hoverable.h"
#include "../utils/point2D.h"

class Unit : public Hoverable {
	public:
		Unit(const int *unitInfo, int armyTextureOffset);
		~Unit();

		const bool &isSelected() const {return selected;}
		void setSelected(bool selected) {this->selected = selected;}
		const int &getSpeed() const {return speed;}
		const Point2D &getPosition() const {return position;}
		void setPosition(Point2D position) {this->position = position;}

		void render(Camera *camera);
		virtual void hovered(Point2D p);

		sf::Sprite *sprite;
		
	private:
		bool selected;
		int speed;
		Point2D position;

		void unitFactory(const int *unitInfo, int armyTextureOffset);
};

#endif
