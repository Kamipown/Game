#include "engine/Engine.hpp"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

using std::cerr;
using std::endl;

static bool init_sdl2(void)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
	{
		cerr << "Unable to initialize SDL2:" << endl << SDL_GetError() << endl;
		return (false);
	}
	return (true);
}

static bool init_sdl2_image(void)
{
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		cerr << "Unable to initialize SDL2_image:" << endl << IMG_GetError() << endl;
		return (false);
	}
	return (true);
}

static bool init_sdl2_mixer(void)
{
	if ((Mix_Init(MIX_INIT_OGG) & MIX_INIT_OGG) != MIX_INIT_OGG)
	{
		cerr << "Unable to initialize SDL2_mixer:" << endl << Mix_GetError() << endl;
		return (false);
	}
	return (true);
}

static bool init_sdl2_ttf(void)
{	
	if (TTF_Init() == -1)
	{
		cerr << "Unable to initialize SDL2_ttf:" << endl << TTF_GetError() << endl;
		return (false);
	}
	return (true);
}

// Initialize SDL2, SDL2_image, SDL2_mixer, SDL2_ttf
bool Engine::init(void)
{
	return (init_sdl2() && init_sdl2_image() && init_sdl2_mixer() && init_sdl2_ttf());
}

// Quit SDL2, SDL2_image, SDL2_mixer, SDL2_ttf
void Engine::quit(void)
{
	SDL_Quit();
	IMG_Quit();
	Mix_Quit();
	TTF_Quit();
}
