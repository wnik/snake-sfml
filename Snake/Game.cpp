#include "Game.h"
#include "GameState.h"


Snake::Game::Game() : 
	mWindowWidth(800), 
	mWindowHeight(600)
{
	window.create(sf::VideoMode(mWindowWidth, mWindowHeight), "Snake C++ SFML");
	view = sf::View(sf::FloatRect(0.0f, 0.0f, static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)));
	window.setView(view);
}


Snake::Game::~Game()
{
	while (!mStates.empty())
		popState();
}

void Snake::Game::gameLoop()
{
	const sf::Time timePerFrame = sf::seconds(1.0f / 10.0f);
	sf::Clock clock;
	sf::Time lastTime = sf::Time::Zero;

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		lastTime += elapsed;

		if (getState() == nullptr)
			continue;

		getState()->input();
		while (lastTime > timePerFrame)
		{
			lastTime -= timePerFrame;
			getState()->update();
		}
		
		window.clear();
		window.setView(view);
		getState()->draw();
		window.display();
	}

}

void Snake::Game::changeState(std::shared_ptr<Snake::GameState> state)
{
	popState();

	pushState(state);
}

void Snake::Game::pushState(std::shared_ptr<Snake::GameState> state)
{
	mStates.push(state);
}

void Snake::Game::popState()
{
	if (!mStates.empty())
		mStates.pop();
}

std::shared_ptr<Snake::GameState> Snake::Game::getState()
{
	if (mStates.empty())
		return nullptr;

	return mStates.top();
}

const unsigned int & Snake::Game::getWindowWidth() const
{
	return mWindowWidth;
}

const unsigned int & Snake::Game::getWindowHeight() const
{
	return mWindowHeight;
}
