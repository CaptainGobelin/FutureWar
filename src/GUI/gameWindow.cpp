#include "../headers/GUI/gameWindow.h"

void GameWindow::setOptions() {
	window.create(sf::VideoMode(L_WINDOW, H_WINDOW, 32), "Pouet Engine");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);
	viewGame.reset(sf::FloatRect(0, 0, L_WINDOW, H_WINDOW));
	viewGame.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
	window.setView(viewGame);
}

int GameWindow::recupInput(bool isActive, sf::Event event) {
	int value = INVALID_INPUT;
	while (value == INVALID_INPUT) {
		if (isActive)
			GameWindow::window.pollEvent(event);
		else
			GameWindow::window.waitEvent(event);
		if (event.type == sf::Event::Closed) {
			value = CLOSE_INPUT;
			return value;
		}
		else if (event.type == sf::Event::GainedFocus) {
			GameWindow::window.display();
			return value;
		}
		else if (event.type == sf::Event::LostFocus) {
			GameWindow::window.display();
			return value;
		}
		else if (event.type == sf::Event::Resized) {
			GameWindow::window.display();
			return value;
		}
		if (isActive) {
			//Active exclusive event (especially mouse events)
		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				value = UP_INPUT;
				return value;
			}
			if (event.key.code == sf::Keyboard::Down) {
				value = DOWN_INPUT;
				return value;
			}
			if (event.key.code == sf::Keyboard::Right) {
				value = RIGHT_INPUT;
				return value;
			}
			if (event.key.code == sf::Keyboard::Left) {
				value = LEFT_INPUT;
				return value;
			}
			if (event.key.code == sf::Keyboard::Escape) {
				value = CLOSE_INPUT;
				return value;
			}
			if (event.key.code == sf::Keyboard::Return) {
				value = ENTER_INPUT;
				return value;
			}
		}
		else {
			if (isActive) {
				value = NO_INPUT;
				return value;
			}
			else
				value = INVALID_INPUT;
		}
	}
	return value;
}