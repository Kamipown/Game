#include "game/Game.hpp"

#include <SDL2/SDL.h>

Game::Game(void)
{
	this->config.parse("game.config");
	this->config.log();
	this->config.save();

	this->window.open(
		this->config.get_int("window_width"),
		this->config.get_int("window_height"),
		this->config.get_bool("window_fullscreen")
	);
	SDL_Delay(2000);
	this->window.close();
}

Game::~Game(void)
{
	
}
