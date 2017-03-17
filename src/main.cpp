#include "headers/Controller/gameController.h"

sf::RenderWindow GameWindow::window;
sf::View GameWindow::viewGame;
bool GameWindow::isFullscreen;

//Default options
int OptionsFile::frameLimit = 30;
bool OptionsFile::vSync = true;
sf::Keyboard::Key OptionsFile::upGameKey = sf::Keyboard::Up;
sf::Keyboard::Key OptionsFile::downGameKey = sf::Keyboard::Down;
sf::Keyboard::Key OptionsFile::rightGameKey = sf::Keyboard::Right;
sf::Keyboard::Key OptionsFile::leftGameKey = sf::Keyboard::Left;
sf::Keyboard::Key OptionsFile::exitGameKey = sf::Keyboard::Escape;
sf::Keyboard::Key OptionsFile::confirmGameKey = sf::Keyboard::Return;
sf::Keyboard::Key OptionsFile::cancelGameKey = sf::Keyboard::N;

std::list<Animable*> Animable::animations;
std::list<Hoverable*> Hoverable::hoverableElements;
std::list<tuple<sf::Drawable*, int, bool> > Drawable::renderQueue;

sf::Texture Textures::texturesStart;
sf::Texture Textures::texturesUnits;
sf::Texture Textures::texturesMap;
sf::Texture Textures::texturesInterface;

int main(int argc, char *argv[]) {
	//Initialize game
	GameController game;
	//Launch the game
	game.launch();
	return 0;
}
