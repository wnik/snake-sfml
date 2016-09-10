#include "MenuState.h"
#include "PlayState.h"
#include "InstructionsState.h"

Snake::MenuState::MenuState(Game * game) : 
	mBackground(ResourceManager::getInstance().getTexture("menuBackground.jpg"))
{
	this->game = game;

	ResourceManager & rManager = ResourceManager::getInstance();

	mMenu.addElement(GuiElement(sf::Vector2f(200, 50), "New Game", "new_game", rManager.getTheme("menuButton"), 25, 10, true));
	mMenu.addElement(GuiElement(sf::Vector2f(200, 50), "Instructions", "instructions", rManager.getTheme("menuButton"), 25, 10, true));
	mMenu.addElement(GuiElement(sf::Vector2f(200, 50), "Quit", "quit", rManager.getTheme("menuButton"), 25, 10, true));
	mMenu.setPosition(sf::Vector2f(static_cast<float>(this->game->window.getSize().x / 2.0f), static_cast<float>(this->game->window.getSize().y / 2.0f)));
	mMenu.display();
}


Snake::MenuState::~MenuState()
{
	
}

void Snake::MenuState::input()
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
					game->window.close();

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

					if (action == "new_game")
					{
						loadGame();
					}

					else if (action == "instructions")
					{
						game->pushState(std::make_shared<InstructionsState>(game));
					}

					else if (action == "quit")
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

void Snake::MenuState::update()
{

}

void Snake::MenuState::draw()
{
	game->window.draw(mBackground);
	game->window.draw(mMenu);
}

void Snake::MenuState::loadGame() const
{
	game->pushState(std::make_shared<PlayState>(game));
}

void Snake::MenuState::restart()
{

}
