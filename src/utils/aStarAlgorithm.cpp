#include "../headers/utils/aStarAlgorithm.h"

bool operator< (AStarNode const &n1, AStarNode const &n2) {
	if (n1.h == n2.h)
		return n1.cell < n2.cell;
    return n1.h < n2.h; 
}

struct AStarNodePtrComp {
	bool operator()(const AStarNode *n1, const AStarNode *n2) const {return *n1 < *n2;}
};

struct AStarNodePtrComp2 {
	bool operator()(const AStarNode *n1, const AStarNode *n2) const {return n1->cell < n2->cell;}
};

std::vector<tuple<Cell*, int> > AStarAlgorithm::apply(Map *map, Unit *unit, Cell *start, Cell *end) {
	std::vector<tuple<Cell*, int> > result;
	if (start == end)
		return result;
	if (end->unit != NULL)
		return result;
	int offsets[4][2] = {
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}
	};
	std::set<AStarNode*, AStarNodePtrComp2> closedList;
	std::multiset<AStarNode*, AStarNodePtrComp> openList;
	openList.insert(new AStarNode(end, start, 0));
	while (!openList.empty()) {
		//Pop front openList
		AStarNode *u =  *openList.begin();
		openList.erase(openList.begin());
		//if current is objective, success
		if (u->cell == end) {
			AStarNode *pointer = u;
			while (pointer != NULL) {
				result.push_back(tuple<Cell*, int>(pointer->cell, pointer->path));
				pointer = pointer->previous;
			}
			std::reverse(result.begin(), result.end());
			//clean memory
			std::multiset<AStarNode*>::iterator it;
			for (it=openList.begin(); it!=openList.end(); it++)
				delete *it;
			std::set<AStarNode*>::iterator it2;
			for (it2=closedList.begin(); it2!=closedList.end(); it2++)
				delete *it2;
			delete u;
			return result;
		}
		//For all current node's neighbours
		for (int i=0;i<4;i++) {
			int neighboursX = (int)u->cell->getPosition().getX()+offsets[i][0];
			int neighboursY = (int)u->cell->getPosition().getY()+offsets[i][1];
			//If neighbour is accessible
			if (map->isInLimits(Point2D(neighboursX, neighboursY))) {
				if (!map->canGo(unit, Point2D(neighboursX, neighboursY)))
					continue;
				if (u->cost >= unit->getSpeed())
					continue;
				AStarNode *v = new AStarNode(end, &(map->cells[neighboursX][neighboursY]), u->cost+1);
				v->path = i;
				v->previous = u;
				//Add to openList (only if not present with lower cost)
				if (closedList.find(v) == closedList.end())
					openList.insert(v);
				else {
					if ((*closedList.find(v))->cost > v->cost) {
						(*closedList.find(v))->cost = v->cost;
						openList.insert(v);
					}
					else
						delete v;
				}
			}
		}
		//Add current node to closedList (is already present delete current node)
		u->h = closedList.size();
		if (!std::get<1>(closedList.insert(u)))
			delete u;
	}
	//if openList is empty fail
	//clean memory
	std::multiset<AStarNode*>::iterator it;
	for (it=openList.begin(); it!=openList.end(); it++)
		delete *it;
	std::set<AStarNode*>::iterator it2;
	for (it2=closedList.begin(); it2!=closedList.end(); it2++)
		delete *it2;
	return result;
}