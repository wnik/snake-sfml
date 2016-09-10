#pragma once
#include <SFML\Graphics.hpp>
#include <unordered_map>
#include <vector>
#include "Box.h"


namespace Snake {
	class Instructions : public Box, public sf::Drawable, public sf::Transformable
	{
	public:

		         Instructions(std::string title, sf::Vector2f windowSize, std::unordered_map<std::string, std::string> descriptions);
		        ~Instructions();

		void     setTextSettings();
		void     setIcons(std::unordered_map<std::string, std::string> descriptions);
		void     setIconsPos();

		void     draw(sf::RenderTarget & target, sf::RenderStates states) const;

	private:

		std::vector<sf::Sprite>                   mIcons;
		std::unordered_map<std::string, sf::Text> mDescriptions;
		float                                     mFontSize;

	};
}
