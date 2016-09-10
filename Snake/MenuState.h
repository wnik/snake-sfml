#pragma once
#include <SFML\Graphics.hpp>
#include "GameState.h"
#include "Game.h"
#include "Gui.h"
#include "ResourceManager.h"

namespace Snake {

	class MenuState : public GameState
	{
	public:

		explicit MenuState(Game * game);
		~MenuState();

		virtual void input()      override;
		virtual void update()     override;
		virtual void draw()       override;
		virtual void restart()    override;

		void         loadGame()   const;

	private:

		sf::Sprite mBackground;
		Gui        mMenu;

	};
}
