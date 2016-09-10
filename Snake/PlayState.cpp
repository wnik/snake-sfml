#include "PlayState.h"
#include <SFML\Graphics.hpp>
#include <random>
#include "Game.h"
#include "ResourceManager.h"
#include "GameOverState.h"
#include "InGameMenuState.h"


Snake::PlayState::PlayState(Game * game) :
	mBackground(ResourceManager::getInstance().getTexture("playBackground.jpg")),
	mBoard(game->getWindowWidth(), game->getWindowHeight()),
	mScore(mBoard.getMarginRight(), game->getWindowWidth(), game->getWindowHeight())
{
	this->game = game;

	spawnPlayer();
	spawnFood();
}


Snake::PlayState::~PlayState()
{
}

void Snake::PlayState::input()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			game->window.close();
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				openInGameMenu();
			}

			else if (event.key.code == sf::Keyboard::P)
			{
				openInGameMenu();
			}

			else if (event.key.code == sf::Keyboard::R)
			{
				restart();
			}

			else if (event.key.code == sf::Keyboard::Up)
			{
				mPlayer->setDirection(0);
			}

			else if (event.key.code == sf::Keyboard::Down)
			{
				mPlayer->setDirection(1);
			}

			else if (event.key.code == sf::Keyboard::Left)
			{
				mPlayer->setDirection(2);
			}

			else if (event.key.code == sf::Keyboard::Right)
			{
				mPlayer->setDirection(3);
			}
			break;

		case sf::Event::Resized:
			game->window.setView(sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(event.size.width), static_cast<float>(event.size.height))));

		default:
			break;
		}
	}
}

void Snake::PlayState::update()
{
	mPlayer->move();
	mPlayer->updateSnakeColor();
	collisionPlayerVsBorder();
	collisionPlayerVsFood();
	collisionPlayerVsNodes();
}

void Snake::PlayState::draw()
{
	game->window.draw(mBackground);
	game->window.draw(mBoard);
	game->window.draw(mScore);
	game->window.draw(mFood->getSprite());
	game->window.draw(*mPlayer);
}

unsigned int Snake::PlayState::calculateScore()
{
	unsigned int tempScore                = 0;
	float        tempDistancePoints[7][2] = { 30.0f, 2,
											  25.0f, 3,
											  20.0f, 4,
											  15.0f, 5,
											  10.0f, 6,
											  6.0f,  7,
											  3.0f,  8,
	                                        };

	unsigned int tempDistance = mPlayer->getTraveledDistance();
	unsigned int rows         = sizeof(tempDistancePoints) / sizeof(tempDistancePoints[0]);


	for (unsigned int i = 0; i < rows; ++i)
	{
		if (tempDistance < tempDistancePoints[i][0])
		{
			tempScore = tempDistancePoints[i][1];
		}

	}

	return tempScore != 0 ? tempScore : 1;
}

void Snake::PlayState::collisionPlayerVsBorder()
{
	unsigned int tempNodeSize        = mBoard.getNodeSize();
	float        tempBorderSize      = mBoard.getBorderSize();
	sf::Vector2f tempBoardDimensions = mBoard.getBoardDimensions();
	sf::Vector2f tempBoardPos        = mBoard.getStartPos();

	if (mPlayer->getFirstNode().getPos().x + tempNodeSize / 2.0f > tempBoardDimensions.x + tempBoardPos.x + tempBorderSize)
		gameOver();

	else if (mPlayer->getFirstNode().getPos().x - tempNodeSize / 2.0f - tempBorderSize < tempBoardPos.x)
		gameOver();

	else if (mPlayer->getFirstNode().getPos().y + tempNodeSize / 2.0f > tempBoardDimensions.y + tempBoardPos.y + tempBorderSize)
		gameOver();

	else if (mPlayer->getFirstNode().getPos().y - tempNodeSize / 2.0f - tempBorderSize < tempBoardPos.y)
		gameOver();
}

void Snake::PlayState::collisionPlayerVsFood()
{
	if (mPlayer->getFirstNode().getBlock().getGlobalBounds().intersects(mFood->getSprite().getGlobalBounds()))
	{
		mScore.addScore(calculateScore());
		mPlayer->resetTraveledDistance();
		mFood.reset();
		spawnFood();
		mPlayer->addNode(mPlayer->getDirection(), mPlayer->getLastNode().getPos());
	}
}

void Snake::PlayState::collisionPlayerVsNodes()
{
	if (mPlayer->isColliding())
	{
		gameOver();
	}

	mPlayer->collisionPlayerVsNodes();
}

void Snake::PlayState::spawnPlayer()
{

	mPlayer = std::make_unique<Snake>(generatePosition(), mBoard.getNodeSize());
}

void Snake::PlayState::spawnFood()
{
	mFood   = std::make_unique<Food>(generatePosition());
}

sf::Vector2f Snake::PlayState::generatePosition()
{
	float tempNodeSize      = static_cast<float>(mBoard.getNodeSize());
	float COLS              = mBoard.getBoardDimensions().x / tempNodeSize;
	float ROWS              = mBoard.getBoardDimensions().y / tempNodeSize;

	unsigned int colNumber  = generateRandomNumber(COLS);
	unsigned int rowNumber  = generateRandomNumber(ROWS);

	return sf::Vector2f(mBoard.getStartPos().x + tempNodeSize / 2.0f + mBoard.getBorderSize() + static_cast<float>(colNumber) * tempNodeSize, mBoard.getStartPos().y + tempNodeSize / 2.0f + mBoard.getBorderSize() + static_cast<float>(rowNumber) * tempNodeSize);
}

unsigned int Snake::PlayState::generateRandomNumber(unsigned int max)
{
	std::random_device rd;
	std::mt19937 randomNumbers(rd());

	std::uniform_int_distribution<int> randomRange(1, max - 1);
	return randomRange(randomNumbers);

}

void Snake::PlayState::gameOver() const
{
	game->pushState(std::make_shared<GameOverState>(game, mScore.getScore()));
}

void Snake::PlayState::openInGameMenu() const
{
	game->pushState(std::make_shared<InGameMenuState>(game));
}

void Snake::PlayState::restart()
{
	mScore.reset();
	mFood.reset();
	mPlayer.reset();
	spawnFood();
	spawnPlayer();
}
