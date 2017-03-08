#ifndef COMPLEX_SHAPE_H
#define COMPLEX_SHAPE_H

#include "../include/const.h"
#include "../include/lib.h"

class ComplexShape : public sf::Drawable, public sf::Transformable {
	public:

		ComplexShape(sf::VertexArray *vertices, sf::Texture *texture);

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