#pragma once
#include <SFML\Graphics.hpp>
#include "GuiStyle.h"
#include "GuiElement.h"
#include <vector>

namespace Snake {
	class Gui : public sf::Drawable, public sf::Transformable
	{
	public:

		Gui();
		~Gui();

		void                      addElement(GuiElement element);
		const         std::string getAction(sf::Vector2f mousePos)                         const;
		int                       getElement(sf::Vector2f mousePos)                        const;
		void                      draw(sf::RenderTarget & target, sf::RenderStates states) const;
		void                      display();
		void                      highlight(const int element);

	private:

		std::vector<GuiElement> mElements;

	};
}