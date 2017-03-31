#include "../headers/utils/textures.h"

void Textures::loadTextures(const char *path) {
	loadFromImage(&texturesStart, path+(std::string)"int/title_screen.png");
	loadFromImage(&texturesUnits, path+(std::string)"sprites/armies_texture.png");
	loadFromImage(&texturesEffects, path+(std::string)"sprites/effects_textures.png");
	loadFromImage(&texturesMap, path+(std::string)"sprites/terrain_textures.png");
	loadFromImage(&texturesInterface, path+(std::string)"int/interface_textures.png");
}

void Textures::loadFromImage(sf::Texture *texture, std::string path) {
	sf::Image image;
	image.loadFromFile(path);
	image.createMaskFromColor(sf::Color::Green);
	texture->loadFromImage(image);
}

void Textures::setTile(sf::Sprite *sprite, int xTile, int yTile) {
	sf::Vector2i offset(SPRITE_SIZE, SPRITE_SIZE);
	float scale = (float)CELL_SIZE/SPRITE_SIZE;
	sprite->setScale(scale, scale);
	sprite->setTextureRect(sf::IntRect(sf::Vector2i(xTile*SPRITE_SIZE, yTile*SPRITE_SIZE), offset));
}
