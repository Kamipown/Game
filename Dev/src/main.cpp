#define SDL_MAIN_HANDLED

#include <cstdlib>

#include "engine/Engine.hpp"
#include "game/Game.hpp"

static void start()
{
	Game game;
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	Engine engine;

	if (engine.init())
	{
		start();
		engine.quit();
	}
	system("pause");
	return (0);
}
