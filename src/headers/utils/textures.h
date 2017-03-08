#ifndef TEXTURES_H
#define TEXTURES_H

#include "../include/const.h"
#include "../include/lib.h"

class Textures {
	public:
		static void loadTextures(const char *path);
		static sf::Texture texturesStart;
		static sf::Texture texturesUnits;
		static sf::Texture texturesMap;
};

#endif
