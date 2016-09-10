#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include "Node.h"

namespace Snake {
	class Snake : public sf::Drawable, public sf::Transformable
	{
	public:

		Snake(sf::Vector2f pos, unsigned int nodeSize);
		~Snake();

		void                 move();
		void                 updateSnakeColor();
		void                 draw(sf::RenderTarget & target, sf::RenderStates states) const;
		void                 setDirection(unsigned int direction);
		void                 addNode(unsigned int currentDirection, sf::Vector2f firstNodePos);
		const unsigned int   getDirection()                                           const;
		const Node         & getFirstNode()                                           const;
		const Node         & getLastNode()                                            const;
		const bool         & isColliding()                                            const;
		const unsigned int & getTraveledDistance()                                    const;
		void                 collisionPlayerVsNodes();
		void                 resetTraveledDistance();

	private:

		enum Directions           { UP, DOWN, LEFT, RIGHT };
		Directions                mDirection;
		Directions                mPrevDirection;
		std::list<Node>           mNodes;
		std::list<Node>::iterator mIt;
		float                     mNodeSize;
		bool                      mIsColliding;
		unsigned int              mTraveledDistance;

	};
}
