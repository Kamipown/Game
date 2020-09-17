#include "Game.hpp"

#include <iostream>

Game::Game(void)
{
	if (!this->sdl2_manager.init())
	{
		std::cerr << "SDL2 initialization failed" << std::endl;
		return ;
	}
}

Game::~Game(void)
{
	this->sdl2_manager.quit();
}
