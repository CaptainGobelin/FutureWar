#ifndef OPTIONS_H
#define OPTIONS_H

#include "../include/const.h"
#include "../include/lib.h"

class OptionsFile {
	public:
		static bool load();
		static int frameLimit;
		static bool vSync;
		static sf::Keyboard::Key upGameKey;
		static sf::Keyboard::Key downGameKey;
		static sf::Keyboard::Key rightGameKey;
		static sf::Keyboard::Key leftGameKey;
		static sf::Keyboard::Key exitGameKey;
		static sf::Keyboard::Key confirmGameKey;
		static sf::Keyboard::Key cancelGameKey;

	private:
		static void setOption(std::string line);
		static bool toBool(std::string const& s);
		static sf::Keyboard::Key toKey(std::string const& s);
};

#endif
