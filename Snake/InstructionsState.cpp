#include "InstructionsState.h"
#include "ResourceManager.h"
#include "Game.h"


Snake::InstructionsState::InstructionsState(Game * game) :
	mInstructions("INSTRUCTIONS",
	sf::Vector2f(game->window.getSize()),
	{ {"arrows", "Movement"},
	  {"p",      "Pause/Unpause game"},
	  {"r",      "Restart game"},
	  {"esc",    "In game menu/Back/Exit"} })
{
	this->game = game;

	ResourceManager & rManager = ResourceManager::getInstance();

	mBackground.setFillColor(rManager.getTheme("inGameMenu").getStyle("background"));
	mBackground.setSize(sf::Vector2f(this->game->window.getSize()));

}


Snake::InstructionsState::~InstructionsState()
{
}

void Snake::InstructionsState::input()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			game->window.close();
			break;
		}

		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
				game->popState();

			break;
		}

		case sf::Event::Resized:
		{
			game->window.setView(sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(event.size.width), static_cast<float>(event.size.height))));

			break;
		}

		default:
			break;
		}
	}
}

void Snake::InstructionsState::update()
{

}

void Snake::InstructionsState::draw()
{
	game->window.draw(mBackground);
	game->window.draw(mInstructions);
}

void Snake::InstructionsState::restart()
{

}
