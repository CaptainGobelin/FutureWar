#include "../headers/Controller/gameController.h"

GameController::GameController() {
	//Rand initialization
	srand (time(NULL));
	//Open the window
	GameWindow::setOptions();
	//Load textures
	Textures::loadTextures(TEXTURES_PATH);

	this->camera = new Camera();
	this->map = new Map(10, 10);
	this->playerArmy = new Army(fedsArmyList);
	this->aiArmy = new Army(mechsArmyList);
}

void GameController::launch() {
	this->titleScreen.setTexture(Textures::texturesStart);
	this->titleScreen.setPosition(0,0);
	int choice = INIT_CHOICE;
	sf::Event event;
	while (choice != CLOSE_INPUT) {
		GameWindow::window.clear();
		GameWindow::window.draw(this->titleScreen);
		GameWindow::window.display();
		choice = GameWindow::recupInput(false, event);
		if (choice == CLOSE_INPUT) {
			return;
		}
		else if (choice == ENTER_INPUT) {
			gameLoop();
			return;
		}
	}
}

void GameController::gameLoop() {
	for (int i=0;i<playerArmy->units.size();i++) {
		map->rows[1][1+i].setUnit(playerArmy->units[i]);
	}
	for (int i=0;i<aiArmy->units.size();i++) {
		map->rows[map->getWidth()-2][map->getHeight()-2-i].setUnit(aiArmy->units[i]);
		aiArmy->units[i]->sprite->setOrigin(CELL_SIZE, 0);
		aiArmy->units[i]->sprite->setScale(-1.f, 1.f);
	}
	int choice = INIT_CHOICE;
	sf::Event event;
	while (choice != CLOSE_INPUT) {
		hoverEvent();
		render();
		choice = GameWindow::recupInput(true, event);
		//Clear queue event
		sf::Event trashcan;
		while (GameWindow::window.pollEvent(trashcan));
		if (choice == UP_INPUT) {
			camera->move(Point2D(0, -12));
		} else if (choice == DOWN_INPUT) {
			camera->move(Point2D(0, 12));
		} else if (choice == LEFT_INPUT) {
			camera->move(Point2D(-12, 0));
		} else if (choice == RIGHT_INPUT) {
			camera->move(Point2D(12, 0));
		}
		else if (choice == CLOSE_INPUT) {
			return;
		}
	}
}

void GameController::hoverEvent() {
	sf::Vector2i mousePosition(sf::Mouse::getPosition(GameWindow::window));
	Hoverable::checkHoverEvents(mousePosition);
}

void GameController::render() {
	GameWindow::window.clear();
	map->render(camera);
	playerArmy->render(camera);
	aiArmy->render(camera);
	Drawable::renderAll();
	GameWindow::window.display();
}