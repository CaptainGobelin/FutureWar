#include "../headers/utils/textures.h"

void Textures::loadTextures(const char *path) {
	texturesStart.loadFromFile(path+(std::string)"int/title_screen.png");

	sf::Image unitSpriteSheet;
	unitSpriteSheet.loadFromFile(path+(std::string)"sprites/armies_texture.png");
	unitSpriteSheet.createMaskFromColor(sf::Color::Green);
	texturesUnits.loadFromImage(unitSpriteSheet);

	sf::Image mapSpriteSheet;
	mapSpriteSheet.loadFromFile(path+(std::string)"sprites/terrain_textures.png");
	mapSpriteSheet.createMaskFromColor(sf::Color::Green);
	texturesMap.loadFromImage(mapSpriteSheet);

	texturesInterface.loadFromFile(path+(std::string)"int/interface_textures.png");
}

void Textures::setTile(sf::Sprite *sprite, int xTile, int yTile) {
	sf::Vector2i offset(CELL_SIZE, CELL_SIZE);
	sprite->setTextureRect(sf::IntRect(sf::Vector2i(xTile*CELL_SIZE, yTile*CELL_SIZE), offset));
}
