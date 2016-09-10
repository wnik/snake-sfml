#pragma once
#include <SFML\Graphics.hpp>


namespace Snake {
	class Score : public sf::Drawable, public sf::Transformable
	{
	public:

		Score(const float & marginRight, const unsigned int & windowWidth, const unsigned int & windowHeight);
		~Score();

		void                 draw(sf::RenderTarget & target, sf::RenderStates states) const;
		void                 addScore(unsigned int score);
		const unsigned int & getScore() const;
		void                 reset();

	private:

		unsigned int mCurrentScore;
		sf::Text     mTitle;
		sf::Text     mText;

	};
}