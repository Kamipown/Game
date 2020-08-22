#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		cerr << "Failure" << endl;
	else
		cout << "Success" << endl;
	system("pause");
	return (0);
}
