#include "../headers/utils/complexShape.h"

ComplexShape::ComplexShape(sf::VertexArray *vertices, sf::Texture *texture) {
    this->vertices = vertices;
    this->texture = texture;
}

ComplexShape::~ComplexShape() {
	delete vertices;
}

void ComplexShape::constructQuad(int data[5], sf::Vector2f cameraOffset, sf::Color color) {
	int offsets[4][2] = {
		{0, 0},
		{1, 0},
		{1, 1},
		{0, 1}
	};
	for (int k=0;k<4;k++) {
		int xPos = (data[1]+offsets[k][0])*CELL_SIZE + cameraOffset.x;
		int yPos = (data[2]+offsets[k][1])*CELL_SIZE + cameraOffset.y;
		(*this->vertices)[data[0]+k].position = sf::Vector2f(xPos, yPos);
		int xTex = offsets[k][0]*CELL_SIZE+data[3];
		int yTex = offsets[k][1]*CELL_SIZE+data[4];
		(*this->vertices)[data[0]+k].texCoords = sf::Vector2f(xTex, yTex);
		(*this->vertices)[data[0]+k].color = color;
	}
}