#define SDL_MAIN_HANDLED
#include <SDL2/include/SDL.h>
#include "window_setup.h"
#include <cstdio>


int main()
{
	windowsetup setup;
	ReadGameInfo(setup);
	SetupWindow(setup);
	printf("bruh it works!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	return 0;
}