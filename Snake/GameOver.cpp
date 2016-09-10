#include "GameOver.h"
#include "ResourceManager.h"


Snake::GameOver::GameOver(std::string title, sf::Vector2f windowSize, unsigned int score) : 
	mFinalScore(score)
{
	ResourceManager & rManager = ResourceManager::getInstance();

	mWindowSize = windowSize;
	mTitleName  = title;

	setupBox(rManager);
	setupTitle(rManager);

	mYourScore.setCharacterSize(32);
	mYourScore.setColor(rManager.getTheme("gameOver").getStyle("title"));
	mYourScore.setFont(rManager.getFont("arial"));
	mYourScore.setString("Your Score:");
	mYourScore.setPosition(mWindowSize.x / 2.0f - mYourScore.getGlobalBounds().width / 2.0f, mWindowSize.y * 0.35f);

	mScore.setCharacterSize(36);
	mScore.setColor(rManager.getTheme("gameOver").getStyle("score"));
	mScore.setFont(rManager.getFont("arial"));
	mScore.setString(std::to_string(mFinalScore));
	mScore.setStyle(sf::Text::Bold);
	mScore.setPosition(mWindowSize.x / 2.0f - mScore.getGlobalBounds().width / 2.0f, mWindowSize.y * 0.45f);
}


Snake::GameOver::~GameOver()
{
}


void Snake::GameOver::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();


	target.draw(getBox(), states);
	target.draw(getTitle(), states);

	target.draw(mYourScore, states);
	target.draw(mScore, states);
}