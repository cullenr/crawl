#include <iostream>
#include <fstream>
#include <SDL.h>
#include "flatbuffers/flatbuffers.h"
#include "generated/flatbuffers/game_generated.h"

using namespace std;

typedef SDL_Point Point;
typedef SDL_Rect Rect;

int main()
{
    std::ifstream input_file("./config.json");
    // () on first argument prevent MVP
    std::string raw_config((std::istreambuf_iterator<char>(input_file)),
                            std::istreambuf_iterator<char>());

    if(raw_config.empty())
    {
        cout << ":( could not load main config" << std::endl;
        return 1;
    }

    const int SCREEN_WIDTH  = 640;
    const int SCREEN_HEIGHT = 480;
    const int FPS = 30;
    const int FRAME_LENGTH_MS = 1000/FPS;
    int current_frame_time_ms;
    bool is_running = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        cout << "SDL_Init" << SDL_GetError() << std::endl;
        return 1;
    }

    //Setup our window and renderer
    SDL_Window *window = SDL_CreateWindow("Crawl", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        cout << "CreateWindow" << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr){
        cout << "CreateRenderer" << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    while(is_running)
    {
        current_frame_time_ms = SDL_GetTicks();

        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch(e.type)
            {
            case SDL_QUIT :
                is_running = false;
                break;
            case SDL_KEYDOWN :
                is_running = false;
                break;
            case SDL_MOUSEBUTTONDOWN :
                is_running = false;
                break;

            }
        }

        // do we have some time to kill before starting the next frame?
        int last_frame_ms = SDL_GetTicks() - current_frame_time_ms;
        if(FRAME_LENGTH_MS > last_frame_ms)
        {
            SDL_Delay(FRAME_LENGTH_MS - last_frame_ms);
        }
    }

    return 0;
}
