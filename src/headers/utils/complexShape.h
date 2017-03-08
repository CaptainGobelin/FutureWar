#ifndef COMPLEX_SHAPE_H
#define COMPLEX_SHAPE_H

#include "../include/const.h"
#include "../include/lib.h"

class ComplexShape : public sf::Drawable, public sf::Transformable {
	public:

		ComplexShape(sf::VertexArray *vertices, sf::Texture *texture);

		//data= {index, x, y, tileOffsetX, tileOffsetY}
		void constructQuad(int data[5], sf::Vector2f cameraOffset);

		sf::VertexArray *vertices;
		sf::Texture *texture;

	private:

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
			states.transform *= getTransform();
			states.texture = texture;
			target.draw(*vertices, states);
		}
};

#endif