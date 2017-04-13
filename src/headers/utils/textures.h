#ifndef TEXTURES_H
#define TEXTURES_H

#include "../include/const.h"
#include "../include/lib.h"

class Textures {
	public:
		static void loadTextures(const char *path);
		static void setTile(sf::Sprite *sprite, int xTile, int yTile);

		static sf::Texture texturesStart;
		static sf::Texture texturesUnits;
		static sf::Texture texturesEffects;
		static sf::Texture texturesMap;
		static sf::Texture texturesInterface;
		static sf::Font normalFont;

	private:
		static void loadFromImage(sf::Texture *texture, std::string path);
};

#endif
