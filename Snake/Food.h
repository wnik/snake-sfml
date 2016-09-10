#pragma once
#include <SFML\Graphics.hpp>


namespace Snake {
	class Food
	{
	public:

		explicit Food(sf::Vector2f pos);
		~Food();

		const sf::Sprite & getSprite() const;

	private:

		sf::Vector2f mFoodDimensions;
		sf::Vector2f mPos;
		sf::Sprite   mSprite;

	};
}