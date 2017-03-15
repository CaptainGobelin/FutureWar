#include "../headers/GUI/gameWindow.h"

void GameWindow::setOptions() {
	//Load the game config
	OptionsFile::load();
	window.create(sf::VideoMode(L_WINDOW, H_WINDOW, 32), "Pouet Engine");
	isFullscreen = false;
	window.setVerticalSyncEnabled(OptionsFile::vSync);
	window.setFramerateLimit(OptionsFile::frameLimit);
	viewGame.reset(sf::FloatRect(0, 0, L_WINDOW, H_WINDOW));
	viewGame.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
	window.setView(viewGame);
}

void GameWindow::switchFullscreen() {
	//window.close();
	if (isFullscreen) {
		window.create(sf::VideoMode(L_WINDOW, H_WINDOW, 32), "Pouet Engine");
		viewGame.reset(sf::FloatRect(0, 0, L_WINDOW, H_WINDOW));
		viewGame.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
		window.setView(viewGame);
		isFullscreen = false;
	}
	else {
		window.create(sf::VideoMode(L_WINDOW, H_WINDOW, 32), "Pouet Engine", sf::Style::Fullscreen);
		viewGame.reset(sf::FloatRect(0, 0, L_WINDOW, H_WINDOW));
		viewGame.setViewport(sf::FloatRect(0.1f, 0, .8f, 1.f));
		window.setView(viewGame);
		isFullscreen = true;
	}
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
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				value = LEFT_CLICK_INPUT;
				return value;
			}
			if (event.mouseButton.button == sf::Mouse::Right) {
				value = RIGHT_CLICK_INPUT;
				return value;
			}
		}
		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
				if (event.key.code == sf::Keyboard::Return) {
					switchFullscreen();
					return value;
				}
			if (event.key.code == OptionsFile::upGameKey) {
				value = UP_INPUT;
				return value;
			}
			if (event.key.code == OptionsFile::downGameKey) {
				value = DOWN_INPUT;
				return value;
			}
			if (event.key.code == OptionsFile::rightGameKey) {
				value = RIGHT_INPUT;
				return value;
			}
			if (event.key.code == OptionsFile::leftGameKey) {
				value = LEFT_INPUT;
				return value;
			}
			if (event.key.code == OptionsFile::exitGameKey) {
				value = CLOSE_INPUT;
				return value;
			}
			if (event.key.code == OptionsFile::confirmGameKey) {
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