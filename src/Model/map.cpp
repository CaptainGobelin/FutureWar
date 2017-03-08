#include "../headers/Model/map.h"

Map::Map(int w/*=5*/, int h/*=5*/) : Hoverable(BACKGROUND_LAYER, true) {
	this->width = w;
	this->height = h;

	rows = new Cell* [width];
	for (int i=0;i<width;i++) {
		rows[i] = new Cell[height];
		for (int j=0;j<height;j++) {
			rows[i][j].setValue(false);
			rows[i][j].setPosition(Point2D(i,j));
		}
	}
	setGraphicSize(sf::Vector2f(width*CELL_SIZE, height*CELL_SIZE));
	basicMap();

	constructSprite();
}

Map::~Map() {
	for (int i = 0; i < this->width; i++)
		delete [] this->rows[i];
	delete [] this->rows;
}

Cell Map::getCell(int x, int y) {
	return rows[x][y];
}

Cell Map::getCell(Point2D p) {
	return rows[(int)p.getX()][(int)p.getY()];
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

void Map::hovered(Point2D p) {
	int xPos = (int)(p.getX()-screenPosition.x/CELL_SIZE);
	int yPos = (int)(p.getY()-screenPosition.y/CELL_SIZE);
	rows[xPos][yPos].hovered(screenPosition);
	if (rows[xPos][yPos].unit != NULL) {
		generateMovingMask(rows[xPos][yPos].unit, xPos, yPos);
	}
}

void Map::generateMovingMask(Unit *unit, int x, int y) {
	int offsets[4][2] = {
		{0, 0},
		{1, 0},
		{1, 1},
		{0, 1}
	};
	int maskSize = 1;
	for (int k=1;k<=unit->getSpeed();k++)
		maskSize += 4*k;
	maskSize *= 4;
	ComplexShape *mask = new ComplexShape(new sf::VertexArray(sf::Quads, maskSize), &Textures::texturesMap);
	int count = 0;
	for (int i=-unit->getSpeed();i<=unit->getSpeed();i++)
		for (int j=-(unit->getSpeed()-abs(i));j<=(unit->getSpeed()-abs(i));j++) 
			for (int k=0;k<4;k++) {
				int xPos = (x+i+offsets[k][0])*CELL_SIZE + screenPosition.x;
				int yPos = (y+j+offsets[k][1])*CELL_SIZE + screenPosition.y;
				(*mask->vertices)[count].position = sf::Vector2f(xPos, yPos);
				if (isInLimits(Point2D(x+i, y+j))) {
					if (!rows[x+i][y+j].getValue()) {
						sf::Vector2f texCoord(offsets[k][0]*CELL_SIZE, (1+offsets[k][1])*CELL_SIZE);
						(*mask->vertices)[count].texCoords = texCoord;
						(*mask->vertices)[count].color = sf::Color(255,255,255,100);
					} else {
						sf::Vector2f texCoord((1+offsets[k][0])*CELL_SIZE, (1+offsets[k][1])*CELL_SIZE);
						(*mask->vertices)[count].texCoords = texCoord;
						(*mask->vertices)[count].color = sf::Color(255,255,255,100);
					}
				}
				else
					(*mask->vertices)[count].position = sf::Vector2f(0, 0);
				count++;
			}
	Drawable::addRender(mask, SUB_UNIT_LAYER, true);
}

void Map::render(Camera *camera) {
	setScreenPosition(sf::Vector2f(-camera->getPosition().getX(), -camera->getPosition().getY()));
	mapSprite->setPosition(-camera->getPosition().getX(), -camera->getPosition().getY());
	addRender(mapSprite, false);
}

void Map::basicMap() {
	for (int i=0;i<width;i++) {
		rows[i][0].setValue(true);
		rows[i][height-1].setValue(true);
	}
	for (int j=0;j<height;j++) {
		rows[0][j].setValue(true);
		rows[width-1][j].setValue(true);
	}
}

bool Map::canGo(Unit u, Point2D p) {
	if (!isInLimits(p))
		return false;
	Point2D unitPos(u.getPosition());
	if (unitPos.dist(p) > u.getSpeed())
		return false;
	if (rows[(int)p.getX()][(int)p.getY()].getValue())
		return false;
	return true;
}

void Map::constructSprite() {
	int offsets[4][2] = {
		{0, 0},
		{1, 0},
		{1, 1},
		{0, 1}
	};
	mapSprite = new ComplexShape(new sf::VertexArray(sf::Quads, width*height*4), &Textures::texturesMap);
	for (int i=0;i<width;i++)
		for (int j=0;j<height;j++) 
			for (int k=0;k<4;k++) {
				sf::Vector2f vertexPos((i+offsets[k][0])*CELL_SIZE, (j+offsets[k][1])*CELL_SIZE);
				(*mapSprite->vertices)[(i*4)+j*(width*4)+k].position = vertexPos;
				int tileOffset = 0;
				if (rows[i][j].getValue())
					tileOffset = CELL_SIZE;
				sf::Vector2f texCoord(offsets[k][0]*CELL_SIZE+tileOffset, offsets[k][1]*CELL_SIZE);
				(*mapSprite->vertices)[(i*4)+j*(width*4)+k].texCoords = texCoord;
			}
}