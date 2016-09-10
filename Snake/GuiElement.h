#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "GuiStyle.h"

namespace Snake {
	class GuiElement
	{
	public:

		GuiElement(
			sf::Vector2f size,
			std::string  label,
			std::string  action,
			GuiStyle   & theme,
			unsigned int padding,
			unsigned int marginBottom,
			bool         boldText);
		~GuiElement();

		void                 constructShape();
		void                 constructText();
		void                 centerOrigin();

		const sf::Vector2f & getSize()   const;
		const sf::Shape    & getShape()  const;
		const sf::Text     & getText()   const;
		const std::string  & getAction() const;
		const unsigned int & getMargin() const;
		const GuiStyle     & getTheme()  const;

		void                 setShapeOrigin(const sf::Vector2f & origin);
		void                 setTextOrigin(const float & originX, const float & originY);
		void                 setShapePosition(const sf::Vector2f & position);
		void                 setTextPosition(const float & positionX, const float & positionY);
		void                 setShapeColor(const sf::Color & color);
		void                 setTextColor(const sf::Color & color);

	private:

		sf::Vector2f       mSize;
		sf::RectangleShape mShape;
		std::string        mLabel;
		std::string        mAction;
		sf::Text           mText;
		GuiStyle           mTheme;
		unsigned int       mPadding;
		unsigned int       mMarginBottom;
		bool               mBoldText;
	};
}