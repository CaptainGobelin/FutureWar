#ifndef CGAME_H
#define CGAME_H

#include "../include/lib.h"
#include "../include/const.h"

#include "interfaceController.h"
#include "../utils/textures.h"
#include "../GUI/gameWindow.h"
#include "../GUI/hoverable.h"
#include "../GUI/drawable.h"
#include "../utils/camera.h"
#include "../Model/map.h"
#include "../Model/army.h"

class GameController {
	public:
		GameController();
		~GameController();
		void launch();

	private:
		void gameLoop();
		int recupInput(bool isActive, sf::Event event);
		void hoverEvent();
		void leftClickEvent();
		void clearQueueEvent();
		void render();
		void renderMap();
		void refreshMap();

		InterfaceController interface;

		Map* map;
		Camera* camera;
		Army *playerArmy;
		Army *aiArmy;

		sf::Sprite titleScreen;
};

#endif