#pragma once
#include "GameState.h"
#include "GameOver.h"
#include "Gui.h"

namespace Snake {
	class GameOverState : public GameState
	{

	public:

		GameOverState(Game * game, unsigned int score);
		~GameOverState();

		virtual void input()      override;
		virtual void update()     override;
		virtual void draw()       override;
		virtual void restart()    override;

	private:

		sf::RectangleShape mBackground;
		GameOver           mGameOver;
		Gui                mMenu;

	};
}