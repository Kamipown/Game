#pragma once

#include "engine/Config.hpp"
#include "engine/Window.hpp"

class Game
{
private:
	Config config;
	Window window;

public:
	Game(void);
	~Game(void);
};
