#ifndef ARMY_H
#define ARMY_H

#include "../include/const.h"
#include "../include/lib.h"

#include "unit.h"
#include "armyLists.h"

class Army {
	public:
		Army(const int armyList[][4], bool playerArmy);
		~Army();

		void armyFactory(const int armyList[][4], bool playerArmy);

		void render(Camera *camera);

		std::vector<Unit*> units;
		
	private:
};

#endif