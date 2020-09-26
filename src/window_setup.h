#pragma once
#include <SDL2/include/SDL.h>

struct windowsetup
{
	int xsize;
	int ysize;
	const char* windowtitle;
    Uint32 windowflags;
};

void ReadGameInfo(windowsetup &setup);

bool SetupWindow(windowsetup &setup);

