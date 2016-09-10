#include "Snake.h"
#include "ResourceManager.h"

Snake::Snake::Snake(sf::Vector2f pos, unsigned int nodeSize) :
	mNodeSize(static_cast<float>(nodeSize)),
	mIsColliding(false)
{
	mNodes.emplace_back(Node(mNodeSize, pos));
	mDirection = RIGHT;
}


Snake::Snake::~Snake()
{
	mNodes.clear();
}

void Snake::Snake::move()
{
	sf::Vector2f tempFirstNodePos = mNodes.front().getPos();
	mIt = mNodes.end();
	--mIt;

	switch (mDirection)
	{
		case UP:
			if (mNodes.size() > 1)
			{
				if (mPrevDirection == DOWN)
				{
					mIsColliding = true;
					break;
				}

				mNodes.splice(mNodes.begin(), mNodes, mIt);
				mNodes.front().setPos(sf::Vector2f(tempFirstNodePos.x, tempFirstNodePos.y - mNodeSize));
				++mTraveledDistance;

			}
			else 
			{
				mNodes.back().setPos(sf::Vector2f(mNodes.back().getPos().x, mNodes.back().getPos().y - mNodeSize));
				++mTraveledDistance;
			}

			break;

		case DOWN:
			if (mNodes.size() > 1)
			{
				if (mPrevDirection == UP)
				{
					mIsColliding = true;
					break;
				}

				mNodes.splice(mNodes.begin(), mNodes, mIt);
				mNodes.front().setPos(sf::Vector2f(tempFirstNodePos.x, tempFirstNodePos.y + mNodeSize));
				++mTraveledDistance;

			}
			else
			{
				mNodes.back().setPos(sf::Vector2f(mNodes.back().getPos().x, mNodes.back().getPos().y + mNodeSize));
				++mTraveledDistance;
			}
			break;

		case LEFT:
			if (mNodes.size() > 1)
			{
				if (mPrevDirection == RIGHT)
				{
					mIsColliding = true;
					break;
				}

				mNodes.splice(mNodes.begin(), mNodes, mIt);
				mNodes.front().setPos(sf::Vector2f(tempFirstNodePos.x - mNodeSize, tempFirstNodePos.y));
				++mTraveledDistance;

			}
			else
			{
				mNodes.back().setPos(sf::Vector2f(mNodes.back().getPos().x - mNodeSize, mNodes.back().getPos().y));
				++mTraveledDistance;
			}
			break;

		case RIGHT:
			if (mNodes.size() > 1)
			{
				if (mPrevDirection == LEFT)
				{
					mIsColliding = true;
					break;
				}

				mNodes.splice(mNodes.begin(), mNodes, mIt);
				mNodes.front().setPos(sf::Vector2f(tempFirstNodePos.x + mNodeSize, tempFirstNodePos.y));
				++mTraveledDistance;

			}
			else
			{
				mNodes.back().setPos(sf::Vector2f(mNodes.back().getPos().x + mNodeSize, mNodes.back().getPos().y));
				++mTraveledDistance;
			}
			break;

		default:
			break;
	}
}

void Snake::Snake::updateSnakeColor()
{
	unsigned int current = 0;

	ResourceManager & rManager = ResourceManager::getInstance();

	for (auto & node : mNodes)
	{

		if (current == 0)
			node.setBlockColor(rManager.getTheme("snake").getStyle("headColor"));
		else
			node.setBlockColor(rManager.getTheme("snake").getStyle("bodyColor"));

		current++;
	}
}

void Snake::Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto & node : mNodes)
	{
		target.draw(node.getBlock());
	}
}

void Snake::Snake::setDirection(unsigned int direction)
{
	mPrevDirection  = mDirection;
	mDirection      = static_cast<Directions>(direction);
}

void Snake::Snake::addNode(unsigned int currentDirection, sf::Vector2f lastNodePos)
{
	switch (currentDirection)
	{
		case 0:
			mNodes.emplace_back(Node(mNodeSize, sf::Vector2f(lastNodePos.x, lastNodePos.y + mNodeSize)));
			break;

		case 1:
			mNodes.emplace_back(Node(mNodeSize, sf::Vector2f(lastNodePos.x, lastNodePos.y - mNodeSize)));
			break;

		case 2:
			mNodes.emplace_back(Node(mNodeSize, sf::Vector2f(lastNodePos.x + mNodeSize, lastNodePos.y)));
			break;

		case 3:
			mNodes.emplace_back(Node(mNodeSize, sf::Vector2f(lastNodePos.x - mNodeSize, lastNodePos.y)));
			break;

		default:
			break;
	}
}

const unsigned int Snake::Snake::getDirection() const
{
	return static_cast<unsigned int>(mDirection);
}

const Snake::Node & Snake::Snake::getFirstNode() const
{
	return mNodes.front();
}

const Snake::Node & Snake::Snake::getLastNode() const
{
	return mNodes.back();
}

void Snake::Snake::collisionPlayerVsNodes()
{
	if (mNodes.size() > 1)
	{
		for (auto iter = std::next(mNodes.begin()); iter != mNodes.end(); ++iter)
		{
			if (mNodes.begin()->getBlock().getGlobalBounds().intersects(iter->getBlock().getGlobalBounds()))
			{
				mIsColliding = true;
			}
		}
	}
}

const bool & Snake::Snake::isColliding() const
{
	return mIsColliding;
}

const unsigned int & Snake::Snake::getTraveledDistance() const
{
	return mTraveledDistance;
}

void Snake::Snake::resetTraveledDistance()
{
	mTraveledDistance = 0;
}