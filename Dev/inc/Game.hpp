#pragma once

#include "SDL2_Manager.hpp" 

class Game
{
private:
	SDL2_Manager sdl2_manager;

public:
	Game(void);
	~Game(void);
};
