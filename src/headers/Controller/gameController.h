#ifndef CGAME_H
#define CGAME_H

#include "../include/lib.h"
#include "../include/const.h"

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
		void launch();

	private:
		void gameLoop();
		int recupInput(bool isActive, sf::Event event);
		void hoverEvent();
		void render();
		void renderMap();

		Map* map;
		Camera* camera;
		Army *hjmu;
		Army *mecha;

		sf::Sprite titleScreen;
};

#endif