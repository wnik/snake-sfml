#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "ResourceManager.h"


namespace Snake {
	class Box
	{

	public:

		Box();
		virtual ~Box();

		void setupBox(ResourceManager & rManager);
		void setupTitle(ResourceManager & rManager);

		      sf::Vector2f         getBoxPos();
			  sf::Vector2f         getBoxSize();
		const sf::RectangleShape & getBox()   const;
		const sf::Text           & getTitle() const;

		float              mBorderSize;
		sf::Vector2f       mWindowSize;
		std::string        mTitleName;

	private:

		sf::RectangleShape mBox;
		sf::Text           mTitle;
		float              mFontSize;

	};
}
