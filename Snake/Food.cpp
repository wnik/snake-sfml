#include "Food.h"
#include "ResourceManager.h"


Snake::Food::Food(sf::Vector2f pos) : 
	mFoodDimensions(15, 15), 
	mPos(pos), 
	mSprite(ResourceManager::getInstance().getTexture("food.png"))
{
	mSprite.setPosition(mPos);
	mSprite.setOrigin(mFoodDimensions.x / 2.0f, mFoodDimensions.y / 2.0f);
}


Snake::Food::~Food()
{
}

const sf::Sprite & Snake::Food::getSprite() const
{
	return mSprite;
}
