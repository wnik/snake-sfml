#include "Node.h"
#include "ResourceManager.h"


Snake::Node::Node(float nodeSize, sf::Vector2f pos) : 
	mPos(pos)
{
	mBlock.setFillColor(ResourceManager::getInstance().getTheme("snake").getStyle("bodyColor"));
	mBlock.setSize(sf::Vector2f(nodeSize, nodeSize));
	mBlock.setOrigin(sf::Vector2f(nodeSize / 2.0f, nodeSize / 2.0f));
	mBlock.setPosition(mPos);
}


Snake::Node::~Node()
{
}

const sf::RectangleShape & Snake::Node::getBlock() const
{
	return mBlock;
}

const sf::Vector2f & Snake::Node::getPos() const
{
	return mPos;
}

void Snake::Node::setPos(sf::Vector2f pos)
{
	mPos = pos;
	mBlock.setPosition(pos);
}

void Snake::Node::setBlockColor(sf::Color color)
{
	mBlock.setFillColor(color);
}
