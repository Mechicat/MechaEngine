#define SDL_MAIN_HANDLED
#include <SDL2/include/SDL.h>
#include "engine_setup.h"
#include <cstdio>


int main()
{
	windowsetup setup;
    SDL_Event event;
    SDL_Window* window;
    SDL_Renderer* renderer;

	ReadGameInfo(setup);
	window = SetupWindow(setup);
    renderer = SetupRenderer(window);

    //Create a renderer for the window created above, with the first display driver present
  //and with no additional settings

    while (true) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        }
    }
	return 0;
}