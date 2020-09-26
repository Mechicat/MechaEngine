
#include "window_setup.h"
#include <speedykv/KeyValue.h>
#include <stdlib.h>
#include <stdio.h>

void ReadGameInfo(windowsetup &setup)
{
    KeyValueRoot kv;
    FILE* filp = fopen("cfg/gameinfo.txt", "r");
    char buf[1024];

    fread_s(buf, 1024, sizeof(char), 1024, filp);

    kv.Parse(buf);
    if (kv["WindowXSize"].IsValid())
    {
        setup.xsize = atoi(kv["WindowXSize"].key.string);
    }
    else
    {
        setup.xsize = 640;
    }
    if (kv["WindowYSize"].IsValid())
    {
        setup.ysize = atoi(kv["WindowYSize"].key.string);
    }
    else
    {
        setup.ysize = 480;
    }
    if (kv["WindowTitle"].IsValid())
    {
        setup.windowtitle = kv["WindowTitle"].key.string;
    }
    else
    {
        setup.windowtitle = "MechaEngine";
    }
    //setup.windowflags = atoi(kv["WindowFlags"].key.string);
}

bool SetupWindow(windowsetup &setup)
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Event event;

    setup.windowflags = SDL_WINDOW_RESIZABLE;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return false;
    }

    if (SDL_CreateWindowAndRenderer(setup.xsize, setup.ysize, setup.windowflags, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return false;
    }

    surface = SDL_LoadBMP("sample.bmp");
    if (!surface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface from image: %s", SDL_GetError());
        return false;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
        return false;
    }
    /*SDL_FreeSurface(surface);

    while (1) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        }
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();*/

    return 0;
}
