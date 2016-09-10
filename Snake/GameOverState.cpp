#include "GameOverState.h"
#include <SFML\Graphics.hpp>
#include "Game.h"


Snake::GameOverState::GameOverState(Game * game, unsigned int score) : 
	mGameOver("Game Over",
	sf::Vector2f(game->window.getSize()),
		score)
{
	this->game = game;

	ResourceManager & rManager = ResourceManager::getInstance();

	mBackground.setFillColor(rManager.getTheme("inGameMenu").getStyle("background"));
	mBackground.setSize(sf::Vector2f(this->game->window.getSize()));

	mMenu.addElement(GuiElement(sf::Vector2f(200, 50), "Play Again", "play_again", rManager.getTheme("playAgainButton"), 25, 10, true));
	mMenu.setPosition(sf::Vector2f(static_cast<float>(this->game->window.getSize().x / 2.0f), static_cast<float>(this->game->window.getSize().y / 1.75f)));
	mMenu.display();
}


Snake::GameOverState::~GameOverState()
{
}

void Snake::GameOverState::input()
{
	sf::Event event;

	sf::Vector2f mousePos = game->window.mapPixelToCoords(sf::Mouse::getPosition(game->window), game->view);

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			game->window.close();
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				game->window.close();
			break;

		case sf::Event::Resized:
			game->window.setView(sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(event.size.width), static_cast<float>(event.size.height))));

		case sf::Event::MouseMoved:
		{
			mMenu.highlight(mMenu.getElement(mousePos));

			break;
		}

		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				std::string action = mMenu.getAction(mousePos);

				if (action == "play_again")
				{
					game->popState();
					game->getState()->restart();
				}
			}

			break;
		}

		default:
			break;
		}
	}
}

void Snake::GameOverState::update()
{

}

void Snake::GameOverState::draw()
{
	game->window.draw(mBackground);
	game->window.draw(mGameOver);
	game->window.draw(mMenu);
}

void Snake::GameOverState::restart()
{

}
