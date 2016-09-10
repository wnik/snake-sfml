#include "GuiStyle.h"


Snake::GuiStyle::GuiStyle() : 
	mDefaultColor(255, 0, 0, 255)
{

}

Snake::GuiStyle::~GuiStyle()
{
	mStyles.clear();
}

Snake::GuiStyle::GuiStyle(std::vector<std::pair<std::string, sf::Color> > styles)
{
	for (auto & style : styles)
	{
		mStyles.emplace(style.first, style.second);
	}
}

const sf::Color & Snake::GuiStyle::getStyle(const std::string & name) const
{
	auto iter = mStyles.find(name);
	if (iter != mStyles.end())
	{
		return iter->second;
	}
	else
		return mDefaultColor;
}

