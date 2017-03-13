#ifndef WINDOW_H
#define WINDOW_H

#include "../include/const.h"
#include "../include/lib.h"

#include "../Controller/optionsFile.h"

class GameWindow {
	public:
		static void setOptions();
		static int recupInput(bool isActive, sf::Event event);
		
		static sf::RenderWindow window;
		//Game viewport
		static sf::View viewGame;
};

#endif