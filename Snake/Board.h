#pragma once
#include <SFML\Graphics.hpp>

namespace Snake {
	class Board : public sf::Drawable, public sf::Transformable
	{
	public:

		Board(unsigned int windowWidth, unsigned int windowHeight);
		~Board();

		void                 calculateBoardDimensions(float width, float height);
		void                 draw(sf::RenderTarget & target, sf::RenderStates states) const;
		const sf::Vector2f & getBoardDimensions()                                     const;
		const sf::Vector2f & getStartPos()                                            const;
		const float        & getBorderSize()                                          const;
		const unsigned int   getNodeSize()                                            const; 
		const float        & getMarginRight()                                         const;

	private:

		sf::Vector2f       mBoardDimensions;
		const float        mBorderSize = 25.0f;
		const float        mMargin = 25.0f;
		const float        mMarginRight = 150.0f;
		sf::Vector2f       mStartmPos = sf::Vector2f(mMargin, mMargin);
		sf::RectangleShape mBoardBox;
		unsigned int       mNodeSize = 15;

	};
}

