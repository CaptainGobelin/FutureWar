#include "../headers/Model/map.h"

Map::Map(int w/*=5*/, int h/*=5*/) : Hoverable(BACKGROUND_LAYER, true) {
	this->state = REFRESH_STATE;
	this->width = w;
	this->height = h;

	cells = new Cell* [width];
	for (int i=0;i<width;i++) {
		cells[i] = new Cell[height];
		for (int j=0;j<height;j++) {
			cells[i][j] = Cell(this);
			cells[i][j].setValue(false);
			cells[i][j].setPosition(Point2D(i,j));
		}
	}
	selectedUnit = NULL;
	setGraphicSize(sf::Vector2f(width*CELL_SIZE, height*CELL_SIZE));
	basicMap();

	constructSprite();
}

Map::~Map() {
	for (int i = 0; i < this->width; i++)
		delete [] this->cells[i];
	delete [] this->cells;
}

Cell Map::getCell(int x, int y) {
	return cells[x][y];
}

Cell Map::getCell(Point2D p) {
	return cells[(int)p.getX()][(int)p.getY()];
}

bool Map::isInLimits(Point2D p) {
	if (p.getX() < 0)
		return false;
	if (p.getY() < 0)
		return false;
	if (p.getX() >= width)
		return false;
	if (p.getY() >= height)
		return false;
	return true;
}

void Map::hoverEvent(Point2D p) {
	int xPos = (int)(p.getX()-screenPosition.x/CELL_SIZE);
	int yPos = (int)(p.getY()-screenPosition.y/CELL_SIZE);
	cells[xPos][yPos].hoverEvent();
	if (cells[xPos][yPos].unit != NULL && selectedUnit == NULL) {
		generateMovingMask(cells[xPos][yPos].unit);
		return;
	}
	if (selectedUnit != NULL ) {
		if (canGo(selectedUnit, Point2D(xPos, yPos))) {
			Point2D p = selectedUnit->getPosition();
			std::vector<tuple<Cell*, int> > path = 
				AStarAlgorithm::apply(this, selectedUnit,
					&(cells[(int)p.getX()][(int)p.getY()]), &(cells[xPos][yPos]));
			for (int i=0;i<path.size();i++) {
				int nextPath = -1;
				if (i < path.size()-1)
					nextPath = path[i+1].get<1>();
				path[i].get<0>()->renderArrow(path[i].get<1>(), nextPath);
			}
		}
	}
}

void Map::generateAllMoveList(Army *army) {
	for (unsigned int i=0;i<army->units.size();i++) {
		generateMoveList(army->units[i]);
	}
}

void Map::generateMoveList(Unit *unit) {
	unit->moveReach.clear();
	int x = unit->getPosition().getX();
	int y = unit->getPosition().getY();
	for (int i=-unit->getSpeed();i<=unit->getSpeed();i++)
		for (int j=-(unit->getSpeed()-abs(i));j<=(unit->getSpeed()-abs(i));j++) {
			if (isInLimits(Point2D(x+i, y+j)))
				unit->moveReach.push_back(tuple<Cell *, bool>
					(&cells[x+i][y+j], canReach(unit, &cells[x+i][y+j])));
	}
}

void Map::generateMovingMask(Unit *unit) {
	int maskSize = 4 * (1 + 2*unit->getSpeed()*(unit->getSpeed()+1)); //Math power
	ComplexShape *mask = new ComplexShape(new sf::VertexArray(sf::Quads, maskSize), &Textures::texturesMap);
	int count = 0;
	std::list<tuple<Cell*, bool> >::iterator it;
	for (it=unit->moveReach.begin(); it!=unit->moveReach.end(); it++) {
		int tileOffset = 0;
		int x = (*it).get<0>()->getPosition().getX();
		int y = (*it).get<0>()->getPosition().getY();
		sf::Color color(255, 255, 255, 100);
		if (!(*it).get<1>())
			tileOffset = CELL_SIZE;
		int data[5] = {count, x, y, tileOffset, CELL_SIZE};
		mask->constructQuad(data, screenPosition, color);
		count += 4;
	}
	Drawable::addRender(mask, SUB_UNIT_LAYER, true);
}

void Map::leftClickEvent(Point2D cursor) {
	cursor.divide(CELL_SIZE);
	int x = (int)(cursor.getX()-screenPosition.x/CELL_SIZE);
	int y = (int)(cursor.getY()-screenPosition.y/CELL_SIZE);
	if (selectedUnit == NULL) {
		if (cells[x][y].unit != NULL) {
			selectUnit(cells[x][y].unit);
		}
	} else {
		if (cells[x][y].unit != NULL) {
			selectUnit(cells[x][y].unit);
		} else {
			if (canReach(selectedUnit, &(cells[x][y]))) {
				selectedUnit->move(&(cells[x][y]));
				state = REFRESH_STATE;
			}
			else {
				selectedUnit->setSelected(false);
				selectedUnit = NULL;
			}
		}
	}
}

void Map::render(Camera *camera) {
	setScreenPosition(sf::Vector2f(-camera->getPosition().getX(), -camera->getPosition().getY()));
	mapSprite->setPosition(-camera->getPosition().getX(), -camera->getPosition().getY());
	addRender(mapSprite, false);
	if (selectedUnit != NULL)
		generateMovingMask(selectedUnit);
}

void Map::basicMap() {
	for (int i=0;i<width;i++) {
		cells[i][0].setValue(true);
		cells[i][height-1].setValue(true);
	}
	for (int j=0;j<height;j++) {
		cells[0][j].setValue(true);
		cells[width-1][j].setValue(true);
	}
	cells[2][1].setValue(true);
	cells[width-3][height-2].setValue(true);
}

bool Map::canGo(Unit *u, Point2D p) {
	if (!isInLimits(p))
		return false;
	Point2D unitPos(u->getPosition());
	if (unitPos.dist(p) > u->getSpeed())
		return false;
	if (cells[(int)p.getX()][(int)p.getY()].getValue())
		return false;
	return true;
}

bool Map::canReach(Unit *u, Cell *c) {
	int xPos = (int)u->getPosition().getX();
	int yPos = (int)u->getPosition().getY();
	return !AStarAlgorithm::apply(this, u, &(cells[xPos][yPos]), c).empty();
}

void Map::constructSprite() {
	mapSprite = new ComplexShape(new sf::VertexArray(sf::Quads, width*height*4), &Textures::texturesMap);
	int count = 0;
	for (int i=0;i<width;i++)
		for (int j=0;j<height;j++) {
			int tileOffset = 0;
			if (cells[i][j].getValue())
				tileOffset = CELL_SIZE;
			int data[5] = {count, i, j, tileOffset, 0};
			mapSprite->constructQuad(data, sf::Vector2f(0,0), sf::Color(255, 255, 255, 255));
			count += 4;
		}
}

void Map::selectUnit(Unit *unit) {
	if (selectedUnit != NULL)
		selectedUnit->setSelected(false);
	selectedUnit = unit;
	selectedUnit->setSelected(true);
}