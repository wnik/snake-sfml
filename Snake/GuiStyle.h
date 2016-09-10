#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <string>
#include <unordered_map>

namespace Snake {
	class GuiStyle
	{
	public:

		GuiStyle();
		GuiStyle(std::vector<std::pair<std::string, sf::Color> > styles);
		~GuiStyle();

		const sf::Color & getStyle(const std::string & name) const;

	private:

		std::unordered_map<std::string, sf::Color> mStyles;
		sf::Color                                  mDefaultColor;

	};
}