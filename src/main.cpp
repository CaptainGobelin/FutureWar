#include "headers/Controller/gameController.h"


sf::RenderWindow GameWindow::window;
sf::View GameWindow::viewGame;

std::list<Hoverable*> Hoverable::hoverableElements;
std::list<tuple<sf::Drawable*, int, bool> > Drawable::renderQueue;

sf::Texture Textures::texturesStart;
sf::Texture Textures::texturesUnits;
sf::Texture Textures::texturesMap;

int main(int argc, char *argv[]) {
	//Initialize game
	GameController game;
	//Launch the game
	game.launch();
	return 0;
}
