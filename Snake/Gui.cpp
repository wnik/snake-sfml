#include "Gui.h"


Snake::Gui::Gui()
{

}


Snake::Gui::~Gui()
{
	mElements.clear();
}

void Snake::Gui::addElement(Snake::GuiElement element)
{
	mElements.emplace_back(element);
}

const std::string Snake::Gui::getAction(sf::Vector2f mousePos) const
{
	if (mElements.size() != 0)
	{
		for (auto & element : mElements)
		{
			sf::Vector2f pos = mousePos;
			pos += element.getShape().getOrigin();
			pos -= element.getShape().getPosition();

			if ((pos.x > 0 && pos.x < element.getShape().getScale().x * element.getSize().x) && (pos.y > 0 && pos.y < element.getShape().getScale().y * element.getSize().y))
				return element.getAction();
		}
		return "noaction";
	}
	else
		return "noaction";
}

int Snake::Gui::getElement(sf::Vector2f mousePos) const
{
	if (mElements.size() != 0)
	{
		unsigned int it = 0;
		for (auto & element : mElements)
		{
			sf::Vector2f pos = mousePos;
			pos += element.getShape().getOrigin();
			pos -= element.getShape().getPosition();

			if ((pos.x > 0 && pos.x < element.getShape().getScale().x * element.getSize().x) && (pos.y > 0 && pos.y < element.getShape().getScale().y * element.getSize().y))
				return it;

			++it;
		}
		return -1;
	}
	else
		return -1;
}

void Snake::Gui::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto element : mElements)
	{
		target.draw(element.getShape());
		target.draw(element.getText());
	}
}

void Snake::Gui::display()
{
	sf::Vector2f offset(0.0f, 0.0f);

	for (auto & element : mElements)
	{
		offset.y += element.getMargin();

		sf::Vector2f origin = element.getShape().getOrigin();
		origin -= offset;

		element.setShapeOrigin(origin);
		element.setTextOrigin(element.getText().getLocalBounds().left + element.getText().getLocalBounds().width / 2.0f + origin.x, element.getText().getLocalBounds().top + element.getText().getLocalBounds().height / 2.0f + origin.y);

		element.setShapePosition(this->getPosition());
		element.setTextPosition(this->getPosition().x + element.getShape().getLocalBounds().width / 2.0f, this->getPosition().y + element.getShape().getLocalBounds().height / 2.0f);

		offset.y += element.getSize().y;
	}
}


void Snake::Gui::highlight(const int element)
{
	for (std::size_t i = 0; i < mElements.size(); ++i)
	{
		if (i == element)
		{
			mElements[i].setTextColor(mElements[i].getTheme().getStyle("textHighlight"));
			mElements[i].setShapeColor(mElements[i].getTheme().getStyle("backgroundHighlight"));
		}
		else
		{
			mElements[i].setTextColor(mElements[i].getTheme().getStyle("text"));
			mElements[i].setShapeColor(mElements[i].getTheme().getStyle("background"));
		}
	}
}
