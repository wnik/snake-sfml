#include "GuiElement.h"
#include "ResourceManager.h"


Snake::GuiElement::GuiElement(
	sf::Vector2f size,
	std::string label,
	std::string action,
	Snake::GuiStyle & theme,
	unsigned int padding,
	unsigned int marginBottom,
	bool boldText)
{
	mSize = size;
	mLabel = label;
	mAction = action;
	mTheme = theme;
	mPadding = padding;
	mMarginBottom = marginBottom;
	mBoldText = boldText ? true : false;
	constructShape();
	constructText();
	centerOrigin();
}


Snake::GuiElement::~GuiElement()
{
}

void Snake::GuiElement::constructShape()
{
	mShape.setSize(mSize);
	mShape.setFillColor(mTheme.getStyle("background"));
}

void Snake::GuiElement::constructText()
{
	Snake::ResourceManager & rManager = Snake::ResourceManager::getInstance();

	mText.setString(mLabel);
	mText.setColor(mTheme.getStyle("text"));
	mText.setFont(rManager.getFont("arial"));
	mText.setCharacterSize(static_cast<unsigned int>(mSize.y - mPadding));

	if (mBoldText)
		mText.setStyle(sf::Text::Bold);
}

void Snake::GuiElement::centerOrigin()
{
	mShape.setOrigin(mSize.x / 2, mSize.y / 2);
}

const sf::Vector2f & Snake::GuiElement::getSize() const
{
	return mSize;
}

const sf::Shape & Snake::GuiElement::getShape() const
{
	return mShape;
}

const sf::Text & Snake::GuiElement::getText() const
{
	return mText;
}

const std::string & Snake::GuiElement::getAction() const
{
	return mAction;
}

const unsigned int & Snake::GuiElement::getMargin() const
{
	return mMarginBottom;
}

const Snake::GuiStyle & Snake::GuiElement::getTheme() const
{
	return mTheme;
}

void Snake::GuiElement::setShapeOrigin(const sf::Vector2f & origin)
{
	mShape.setOrigin(origin);
}

void Snake::GuiElement::setTextOrigin(const float & originX, const float & originY)
{
	mText.setOrigin(originX, originY);
}

void Snake::GuiElement::setShapePosition(const sf::Vector2f & position)
{
	mShape.setPosition(position);
}

void Snake::GuiElement::setTextPosition(const float & positionX, const float & positionY)
{
	mText.setPosition(positionX, positionY);
}

void Snake::GuiElement::setShapeColor(const sf::Color & color)
{
	mShape.setFillColor(color);
}

void Snake::GuiElement::setTextColor(const sf::Color & color)
{
	mText.setColor(color);
}
