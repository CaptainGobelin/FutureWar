#ifndef WINDOW_H
#define WINDOW_H

#include "../include/const.h"
#include "../include/lib.h"

#include "../Controller/optionsFile.h"

class GameWindow {
	public:
		static void setOptions();
		static void switchFullscreen();
		static int recupInput(bool isActive, sf::Event event);
		static sf::Vector2i getMousePosition();
		
		static sf::RenderWindow window;
		//Game viewport
		static sf::View viewGame;
		static bool isFullscreen;
};

#endif