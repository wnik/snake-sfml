#pragma once
#include <memory>
#include "GameState.h"
#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include "Score.h"

namespace Snake {
	class PlayState : public GameState
	{
	public:

		explicit PlayState(Game * game);
		~PlayState();

		virtual void input()      override;
		virtual void update()     override;
		virtual void draw()       override;
		virtual void restart()    override;

		unsigned int calculateScore();
		void         collisionPlayerVsBorder();
		void         collisionPlayerVsFood();
		void         collisionPlayerVsNodes();
		void         spawnPlayer();
		void         spawnFood();
		sf::Vector2f generatePosition();
		unsigned int generateRandomNumber(unsigned int max);
		void         gameOver()       const;
		void         openInGameMenu() const;

	private:

		sf::Sprite             mBackground;
		Board                  mBoard;
		std::unique_ptr<Snake> mPlayer;
		std::unique_ptr<Food>  mFood;
		Score                  mScore;

	};
}
