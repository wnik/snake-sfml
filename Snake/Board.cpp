#include "Board.h"
#include "ResourceManager.h"


Snake::Board::Board(unsigned int windowWidth, unsigned int windowHeight)
{
	ResourceManager & rManager = ResourceManager::getInstance();

	calculateBoardDimensions(windowWidth - mMargin - mMarginRight - mBorderSize * 2.0f, windowHeight - 2.0f * mMargin - mBorderSize * 2.0f);

	mBoardBox.setFillColor(rManager.getTheme("board").getStyle("background"));
	mBoardBox.setOutlineColor(rManager.getTheme("board").getStyle("wallColor"));
	mBoardBox.setOutlineThickness(mBorderSize);
	mBoardBox.setSize(mBoardDimensions);
	mBoardBox.setPosition(sf::Vector2f(mMargin + mBorderSize, mMargin + mBorderSize));
}


Snake::Board::~Board()
{
}

void Snake::Board::calculateBoardDimensions(float width, float height)
{
	unsigned int tempWidth = static_cast<int>(width);
	unsigned int tempHeight = static_cast<int>(height);

	if (tempWidth % mNodeSize == 0)
	{
		mBoardDimensions.x = static_cast<float>(tempWidth);
	}

	else
	{
		while (!(tempWidth % mNodeSize == 0))
		{
			--tempWidth;
			if (tempWidth % mNodeSize == 0)
				mBoardDimensions.x = static_cast<float>(tempWidth);
		}
	}

	if (tempHeight % mNodeSize == 0)
	{
		mBoardDimensions.y = static_cast<float>(tempHeight);
	}

	else
	{
		while (!(tempHeight % mNodeSize == 0))
		{
			--tempHeight;
			if (tempHeight % mNodeSize == 0)
				mBoardDimensions.y = static_cast<float>(tempHeight);
		}
	}
}

void Snake::Board::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mBoardBox);
}

const sf::Vector2f & Snake::Board::getBoardDimensions() const
{
	return mBoardBox.getSize();
}

const sf::Vector2f & Snake::Board::getStartPos() const
{
	return mStartmPos;
}

const float & Snake::Board::getBorderSize() const
{
	return mBorderSize;
}

const unsigned int Snake::Board::getNodeSize() const
{
	return mNodeSize;
}

const float & Snake::Board::getMarginRight() const
{
	return mMarginRight;
}