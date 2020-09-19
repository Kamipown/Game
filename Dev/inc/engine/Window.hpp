#pragma once

#include <SDl2/SDL.h>

class Window
{
private:
	SDL_Window *window;

public:
	bool open(int width, int height, bool fullscreen);
	void close(void);
	
	SDL_Window *get_window(void);
};
