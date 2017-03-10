#ifndef A_STAR_ALGO_H
#define A_STAR_ALGO_H

#include "../include/const.h"
#include "../include/lib.h"

#include "point2D.h"
#include "aStarNode.h"
#include "../Model/map.h"

class AStarAlgorithm {
	public:
		static int* apply(Map *map, Cell *start, Cell *end);

		
	private:

		
};

#endif