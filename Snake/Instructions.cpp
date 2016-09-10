#include "Instructions.h"
#include "ResourceManager.h"



Snake::Instructions::Instructions(std::string title, sf::Vector2f windowSize, std::unordered_map<std::string, std::string> descriptions) :
	mFontSize(16)
{
	ResourceManager & rManager = ResourceManager::getInstance();

	mWindowSize = windowSize;
	mTitleName  = title;

	setupBox(rManager);
	setupTitle(rManager);

	for (auto description : descriptions)
	{
		mDescriptions.emplace(description.first, sf::Text());
	}

	for (auto & description : mDescriptions)
	{
		description.second.setString(descriptions.at(description.first));
	}

	setIcons(descriptions);
	setIconsPos();
	setTextSettings();
}


Snake::Instructions::~Instructions()
{
	mIcons.clear();
	mDescriptions.clear();
}

void Snake::Instructions::setTextSettings()
{
	ResourceManager & rManager = ResourceManager::getInstance();

	float off = mIcons[0].getGlobalBounds().height / 2.0f;

	unsigned int i = 0;

	for (auto & description : mDescriptions)
	{
		description.second.setCharacterSize(mFontSize);
		description.second.setFont(rManager.getFont("arial"));
		description.second.setColor(rManager.getTheme("instructions").getStyle("text"));

		float busySpace      = getBoxPos().x + mIcons[i].getPosition().x - getBoxPos().x + mIcons[i].getGlobalBounds().width;
		float space          = getBoxPos().x + getBoxSize().x - busySpace;
		float spaceMinusText = space - description.second.getGlobalBounds().width;
		float oneSideSpace   = spaceMinusText / 2.0f;
		float finalpos       = busySpace + oneSideSpace;

		description.second.setPosition(sf::Vector2f(finalpos, mIcons[0].getPosition().y + off - description.second.getGlobalBounds().height / 2.0f));

		off += mIcons[0].getGlobalBounds().height + description.second.getGlobalBounds().height / 1.25f;
		++i;
	}
}

void Snake::Instructions::setIcons(std::unordered_map<std::string, std::string> descriptions)
{
	for (auto description : descriptions)
	{
		mIcons.emplace_back(sf::Sprite(ResourceManager::getInstance().getTexture(description.first + ".png")));
	}
}

void Snake::Instructions::setIconsPos()
{
	sf::Vector2f off(30.0f, 0.0f);

	for (auto & icon : mIcons)
	{
		icon.setPosition(getBoxPos().x + mBorderSize + off.x, getBoxPos().y + mBorderSize + off.y);

		off.x  = 45.0f;
		off.y += 72.5f;
	}
}

void Snake::Instructions::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	
	target.draw(getBox(), states);
	target.draw(getTitle(), states);

	for (auto & icon : mIcons)
	{
		target.draw(icon, states);
	}

	for (auto & description : mDescriptions)
	{
		target.draw(description.second, states);
	}
}