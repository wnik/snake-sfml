#include "Box.h"


Snake::Box::Box() : 
	mBorderSize(10),
	mFontSize(46)
{

}


Snake::Box::~Box()
{
}

void Snake::Box::setupBox(Snake::ResourceManager & rManager)
{
	mBox.setFillColor(rManager.getTheme("board").getStyle("background"));
	mBox.setOutlineColor(rManager.getTheme("board").getStyle("wallColor"));
	mBox.setOutlineThickness(mBorderSize);
	mBox.setSize(sf::Vector2f(mWindowSize.x / 2.0f, mWindowSize.y / 2.0f));
	mBox.setPosition(mWindowSize.x / 4.0f, mWindowSize.y / 4.0f);
}

void Snake::Box::setupTitle(Snake::ResourceManager & rManager)
{
	mTitle.setCharacterSize(mFontSize);
	mTitle.setFont(rManager.getFont("arial"));
	mTitle.setColor(sf::Color(255, 255, 255, 255));
	mTitle.setString(mTitleName);
	mTitle.setStyle(sf::Text::Bold);
	mTitle.setPosition(mWindowSize.x / 2.0f - mTitle.getGlobalBounds().width / 2.0f, mWindowSize.y * 0.12f);
}

sf::Vector2f Snake::Box::getBoxPos()
{
	return mBox.getPosition();
}

sf::Vector2f Snake::Box::getBoxSize()
{
	return mBox.getSize();
}

const sf::RectangleShape & Snake::Box::getBox() const
{
	return mBox;
}

const sf::Text & Snake::Box::getTitle() const
{
	return mTitle;
}