#pragma once
#include <SFML\Graphics.hpp>
#include "Box.h"


namespace Snake {
	class GameOver : public Box, public sf::Drawable, public sf::Transformable
	{

	public:

		GameOver(std::string title, sf::Vector2f windowSize, unsigned int score);
		~GameOver();

		void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	private:

		sf::Text     mYourScore;
		sf::Text     mScore;
		unsigned int mFinalScore;

	};
}