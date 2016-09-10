#pragma once
#include <memory>
#include <stack>
#include <string>
#include <SFML\Graphics.hpp>
#include "GuiStyle.h"

namespace Snake {
	class GameState;
	class Game
	{
	public:

		Game();
		~Game();

		void                       gameLoop();
		void                       changeState(std::shared_ptr<GameState> state);
		void                       pushState(std::shared_ptr<GameState> state);
		void                       popState();
		std::shared_ptr<GameState> getState();

		const unsigned int       & getWindowWidth()  const;
		const unsigned int       & getWindowHeight() const;

		sf::RenderWindow                        window;
		sf::View                                view;

	private:

		std::stack<std::shared_ptr<GameState> > mStates;
		const unsigned int                      mWindowWidth;
		const unsigned int                      mWindowHeight;

	};
}
