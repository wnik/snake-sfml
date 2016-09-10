#pragma once
#include <SFML\Graphics.hpp>

namespace Snake {
	class Node
	{
	public:

		Node(float nodeSize, sf::Vector2f pos);
		~Node();

		const sf::RectangleShape & getBlock() const;
		const sf::Vector2f       & getPos()   const;
		void                       setPos(sf::Vector2f pos);
		void                       setBlockColor(sf::Color color);

	private:

		sf::Vector2f       mPos;
		sf::RectangleShape mBlock;

	};
}