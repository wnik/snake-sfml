#pragma once
#include "GameState.h"
#include <SFML\Graphics.hpp>
#include "Gui.h"


namespace Snake {
	class InGameMenuState : public GameState
	{

	public:

		explicit InGameMenuState(Game * game);
		~InGameMenuState();

		virtual void input()            override;
		virtual void update()           override;
		virtual void draw()             override;
		virtual void restart()          override;

		void         loadInstructions() const;

	private:

		sf::RectangleShape mBackground;
		sf::Text           mTitle;
		Gui                mMenu;

	};
}