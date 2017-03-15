#include "../headers/GUI/actionMenuButton.h"

ActionMenuButton::ActionMenuButton(Hoverable* parent, std::string name, int yOffset, sf::Font *font) : HoverableComponent(parent) {
	sf::Vector2f position = parent->getScreenPosition();
	position.y += yOffset*CELL_SIZE;
	sf::Vector2i offset(4*CELL_SIZE, CELL_SIZE);
	for (int i=0;i<2;i++) {
		sprite[i] = new sf::Sprite();
		sprite[i]->setTexture(Textures::texturesInterface);
		sprite[i]->setTextureRect(sf::IntRect(sf::Vector2i(0, i*CELL_SIZE), offset));
		sprite[i]->setPosition(position);
	}

	this->name = name;

	if (name.size() > 7)
		name.resize(7);
	text = new sf::Text();
	text->setString(name);
	text->setCharacterSize(CELL_SIZE/2);
	position.y += CELL_SIZE/4;
	position.x += (8-name.size())*(CELL_SIZE/4);
	text->setPosition(position);
	text->setFont(*font);
}

ActionMenuButton::~ActionMenuButton() {
	for (int i=0;i<2;i++)
		delete sprite[i];
	delete text;
}

void ActionMenuButton::render() {
	if (hover) {
		Drawable::addRender(sprite[1], parent->getLayer(), false);
		text->setColor(sf::Color::Yellow);
	}
	else {
		Drawable::addRender(sprite[0], parent->getLayer(), false);
		text->setColor(sf::Color::Green);
	}
	Drawable::addRender(text, parent->getLayer()+1, false);
	hover = false;
}

int ActionMenuButton::hoverEvent() {
	hover = true;
	return 0;
}

int ActionMenuButton::leftClickEvent() {
	return menuStates[name];
}