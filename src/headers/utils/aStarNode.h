#ifndef A_STAR_NODE_H
#define A_STAR_NODE_H

#include "../include/const.h"
#include "../include/lib.h"

#include "point2D.h"
#include "../Model/cell.h"
#include "../Model/map.h"

class AStarNode {
	public:
		AStarNode(Cell *objective, Cell *cell, int cost);
		AStarNode(Cell *cell, int cost, int h);

		Cell *cell;
		AStarNode *previous;
		int cost;
		int h;
		int path;
		
	private:
		
		
};

#endif