#pragma once
#include <SFML\Graphics.hpp>
#include "GameState.h"
#include <memory>
#include <unordered_map>
#include "Instructions.h"


namespace Snake {
	class InstructionsState : public GameState
	{
	public:

		explicit InstructionsState(Game * game);
		        ~InstructionsState();

		virtual void input()   override;
		virtual void update()  override;
		virtual void draw()    override;
		virtual void restart() override;

	private:

		sf::RectangleShape                        mBackground;
		Instructions                              mInstructions;
	};
}