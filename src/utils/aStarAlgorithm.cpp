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

int* AStarAlgorithm::apply(Map *map, Cell *start, Cell *end) {
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
		AStarNode *u =  *openList.begin();
		openList.erase(openList.begin());
		if (u->cell == end) {
			std::cout << "Over" << std::endl;
			AStarNode *pointer = u;
			while (pointer != NULL) {
				std::cout << pointer->path << " <- ";
				pointer = pointer->previous;
			}
			std::cout << std::endl;
			std::multiset<AStarNode*>::iterator it;
			for (it=openList.begin(); it!=openList.end(); it++)
				delete *it;
			std::set<AStarNode*>::iterator it2;
			for (it2=closedList.begin(); it2!=closedList.end(); it2++)
				delete *it2;
			delete u;
			return NULL;
		}
		for (int i=0;i<4;i++) {
			int neighboursX = (int)u->cell->getPosition().getX()+offsets[i][0];
			int neighboursY = (int)u->cell->getPosition().getY()+offsets[i][1];
			if (map->isInLimits(Point2D(neighboursX, neighboursY))) {
				if (map->cells[neighboursX][neighboursY].getValue())
					continue;
				AStarNode *v = new AStarNode(end, &(map->cells[neighboursX][neighboursY]), u->cost+1);
				v->path = i;
				v->previous = u;
				if (closedList.find(v) == closedList.end())
					openList.insert(v);
				else
					delete v;
			}
		}
		u->h = closedList.size();
		if (!std::get<1>(closedList.insert(u)))
			delete u;
	}
	std::multiset<AStarNode*>::iterator it;
	for (it=openList.begin(); it!=openList.end(); it++)
		delete *it;
	std::set<AStarNode*>::iterator it2;
	for (it2=closedList.begin(); it2!=closedList.end(); it2++)
		delete *it2;
	return NULL;
}