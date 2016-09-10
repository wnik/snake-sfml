#include "InGameMenuState.h"
#include "Game.h"
#include "ResourceManager.h"
#include "InstructionsState.h"


Snake::InGameMenuState::InGameMenuState(Game * game)
{
	this->game = game;

	ResourceManager & rManager = ResourceManager::getInstance();

	mBackground.setFillColor(rManager.getTheme("inGameMenu").getStyle("background"));
	mBackground.setSize(sf::Vector2f(this->game->window.getSize()));

	mTitle.setFont(rManager.getFont("arial"));
	mTitle.setString("GAME PAUSED");
	mTitle.setStyle(sf::Text::Bold);
	mTitle.setColor(rManager.getTheme("score").getStyle("title"));
	mTitle.setCharacterSize(32);
	mTitle.setPosition(sf::Vector2f(static_cast<float>(this->game->window.getSize().x / 2.0f - mTitle.getGlobalBounds().width / 2.0f), static_cast<float>(this->game->window.getSize().y / 4.0f)));

	mMenu.addElement(GuiElement(sf::Vector2f(200, 50), "Resume", "resume_game", rManager.getTheme("menuButton"), 25, 10, true));
	mMenu.addElement(GuiElement(sf::Vector2f(200, 50), "Instructions", "instructions", rManager.getTheme("menuButton"), 25, 10, true));
	mMenu.addElement(GuiElement(sf::Vector2f(200, 50), "Quit", "quit_game", rManager.getTheme("menuButton"), 25, 10, true));
	mMenu.setPosition(sf::Vector2f(static_cast<float>(this->game->window.getSize().x / 2.0f), static_cast<float>(this->game->window.getSize().y / 2.5f)));
	mMenu.display();
}


Snake::InGameMenuState::~InGameMenuState()
{
}

void Snake::InGameMenuState::input()
{
	sf::Event event;

	sf::Vector2f mousePos = game->window.mapPixelToCoords(sf::Mouse::getPosition(game->window), game->view);

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

			else if (event.key.code == sf::Keyboard::P)
				game->popState();

			break;
		}

		case sf::Event::Resized:
		{
			game->window.setView(sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(event.size.width), static_cast<float>(event.size.height))));

			break;
		}

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

				if (action == "resume_game")
				{
					game->popState();
				}

				else if (action == "instructions")
				{
					loadInstructions();
				}

				else if (action == "quit_game")
				{
					game->window.close();
				}
			}

			break;
		}

		default:
			break;
		}
	}
}

void Snake::InGameMenuState::update()
{

}

void Snake::InGameMenuState::draw()
{
	game->window.draw(mBackground);
	game->window.draw(mTitle);
	game->window.draw(mMenu);
}

void Snake::InGameMenuState::loadInstructions() const
{
	game->pushState(std::make_shared<InstructionsState>(game));
}

void Snake::InGameMenuState::restart()
{

}
