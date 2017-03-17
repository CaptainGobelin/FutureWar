#include "../headers/Model/army.h"

Army::Army(const int armyList[][4], bool playerArmy) {
	units.clear();
	armyFactory(armyList, playerArmy);
}

Army::~Army() {
	for (unsigned int i=0;i<units.size();i++) {
		delete units[i];
	}
}

void Army::armyFactory(const int armyList[][4], bool playerArmy) {
	for (int i=0;i<armyList[0][0];i++) {
		Unit* unit = new Unit(armyList[i+1], armyList[0][1], playerArmy);
		units.push_back(unit);
	}
}

void Army::render(Camera *camera) {
	for (unsigned int i=0;i<units.size();i++) {
		units[i]->render(camera);
	}
}
