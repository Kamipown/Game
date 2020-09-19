#include "engine/Window.hpp"

#include <iostream>

using std::cerr;
using std::endl;

bool Window::open(int width, int height, bool fullscreen)
{
	this->window = SDL_CreateWindow("BATTLE ARENA", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, (fullscreen ? SDL_WINDOW_FULLSCREEN : 0));
	if (this->window == NULL)
	{
		cerr << "Unable to create window:" << endl << SDL_GetError() << endl;
		return (false);
	}
	return (true);
}

void Window::close(void)
{
	SDL_DestroyWindow(this->window);
}

SDL_Window *Window::get_window(void)
{
	return (this->window);
}
