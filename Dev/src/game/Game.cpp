#include "game/Game.hpp"

#include <iostream>

Game::Game(void)
{
	this->config.parse("game.config");
	this->config.log();
	this->config.save();
}

Game::~Game(void)
{
	
}
