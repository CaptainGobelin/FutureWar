#include "../headers/Controller/gameController.h"

GameController::GameController() {
	//Rand initialization
	srand (time(NULL));
	//Open the window
	GameWindow::setOptions();
	//Load textures
	Textures::loadTextures(TEXTURES_PATH);
	//Init interface
	this->interface = InterfaceController();

	this->camera = new Camera();
	this->map = new Map(&interface, 10, 10);
	this->playerArmy = new Army(fedsArmyList, true);
	this->aiArmy = new Army(mechsArmyList, false);
}

GameController::~GameController() {
	delete camera;
	delete map;
	delete playerArmy;
	delete aiArmy;
}

void GameController::launch() {
	this->titleScreen.setTexture(Textures::texturesStart);
	float imgScaleX = (float)L_WINDOW/titleScreen.getTexture()->getSize().x;
	float imgScaleY = (float)H_WINDOW/titleScreen.getTexture()->getSize().y;
	this->titleScreen.setScale(imgScaleX, imgScaleY);
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
		playerArmy->units[i]->move(&(map->cells[1][1+i]), false);
	}
	for (int i=0;i<aiArmy->units.size();i++) {
		aiArmy->units[i]->move(&(map->cells[map->getWidth()-2][map->getHeight()-2-i]), false);
		aiArmy->units[i]->sprite->setOrigin(SPRITE_SIZE, 0);
		aiArmy->units[i]->sprite->setScale(-(float)CELL_SIZE/SPRITE_SIZE, (float)CELL_SIZE/SPRITE_SIZE);
	}
	bool playerTurn = true;
	int choice = INIT_CHOICE;
	sf::Event event;
	while (choice != CLOSE_INPUT) {
		Animable::computeAnimations();
		refreshMap();
		hoverEvent();
		render();
		choice = GameWindow::recupInput(true, event);
		clearQueueEvent();
		if (choice == UP_INPUT) {
			camera->move(Point2D(0, -12));
		} else if (choice == DOWN_INPUT) {
			camera->move(Point2D(0, 12));
		} else if (choice == LEFT_INPUT) {
			camera->move(Point2D(-12, 0));
		} else if (choice == RIGHT_INPUT) {
			camera->move(Point2D(12, 0));
		} else if (choice == LEFT_CLICK_INPUT) {
			leftClickEvent();
		}
		else if (choice == CLOSE_INPUT) {
			return;
		}
	}
}

void GameController::hoverEvent() {
	Hoverable::checkHoverEvents(GameWindow::getMousePosition());
}

void GameController::leftClickEvent() {
	Hoverable::leftClickEvents(GameWindow::getMousePosition());
}

void GameController::clearQueueEvent() {
	sf::Event trashcan;
	while (GameWindow::window.pollEvent(trashcan));
}

void GameController::render() {
	GameWindow::window.clear();
	map->render(camera);
	playerArmy->render(camera);
	aiArmy->render(camera);
	interface.render();
	Drawable::renderAll();
	GameWindow::window.display();
}
void GameController::refreshMap() {
	if (map->getState() != REFRESH_STATE)
		return;
	map->generateAllMoveList(playerArmy);
	map->generateAllMoveList(aiArmy);
	map->setState(NORMAL_STATE);
}
