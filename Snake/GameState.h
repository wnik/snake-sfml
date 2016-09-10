#pragma once

namespace Snake {
	class Game;
	class GameState
	{
	public:

		GameState();
		virtual ~GameState();

		Game * game;

		virtual void input()      = 0;
		virtual void update()     = 0;
		virtual void draw()       = 0;
		virtual void restart()    = 0;

	};
}

