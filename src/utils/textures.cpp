#include "../headers/utils/textures.h"

void Textures::loadTextures(const char *path) {
	texturesStart.loadFromFile(path+(std::string)"int/title-screen.png");
	sf::Image unitSpriteSheet;
	unitSpriteSheet.loadFromFile(path+(std::string)"sprites/armies_texture.png");
	unitSpriteSheet.createMaskFromColor(sf::Color::Green);
	texturesUnits.loadFromImage(unitSpriteSheet);
	texturesMap.loadFromFile(path+(std::string)"sprites/terrain_textures.png");
}
