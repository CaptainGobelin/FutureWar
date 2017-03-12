#ifndef A_STAR_ALGO_H
#define A_STAR_ALGO_H

#include "../include/const.h"
#include "../include/lib.h"

#include "point2D.h"
#include "aStarNode.h"
#include "../Model/map.h"
#include "../Model/unit.h"

class AStarAlgorithm {
	public:
		static std::vector<tuple<Cell*, int> > apply(Map *map, Unit *unit, Cell *start, Cell *end);

		
	private:

		
};

#endif