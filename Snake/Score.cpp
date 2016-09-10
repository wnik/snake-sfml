#include "Score.h"
#include "ResourceManager.h"
#include <sstream>


Snake::Score::Score(const float & marginRight, const unsigned int & windowWidth, const unsigned int & windowHeight) : 
	mCurrentScore(0)
{
	ResourceManager & rManager = ResourceManager::getInstance();

	mTitle.setFont(rManager.getFont("arial"));
	mTitle.setString("SCORE");
	mTitle.setStyle(sf::Text::Bold);
	mTitle.setColor(rManager.getTheme("score").getStyle("title"));
	mTitle.setCharacterSize(marginRight / 5.0f);
	mTitle.setPosition(sf::Vector2f(windowWidth - marginRight / 2.0f - mTitle.getGlobalBounds().width / 2.0f, windowHeight * 0.4f));

	mText.setFont(rManager.getFont("arial"));
	mText.setString("0");
	mText.setStyle(sf::Text::Bold);
	mText.setColor(rManager.getTheme("score").getStyle("text"));
	mText.setCharacterSize(marginRight / 5.0f);
	mText.setPosition(sf::Vector2f(windowWidth - marginRight / 2.0f - mText.getGlobalBounds().width / 2.0f, windowHeight * 0.45f));
}


Snake::Score::~Score()
{
}

void Snake::Score::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mTitle);
	target.draw(mText);
}

void Snake::Score::addScore(unsigned int score)
{
	mCurrentScore += score;

	mText.setString(std::to_string(mCurrentScore));
}

const unsigned int & Snake::Score::getScore() const
{
	return mCurrentScore;
}

void Snake::Score::reset()
{
	mCurrentScore = 0;
	mText.setString("0");
}