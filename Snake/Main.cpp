#include "Game.h"
#include "MenuState.h"

int main()
{
	Snake::Game game;

	game.pushState(std::make_shared<Snake::MenuState>(&game));
	game.gameLoop();

	return 0;
}