#include "../includes/constants.hpp"

void    cleanup(GraphicsEngine &engine){
    if (engine.win != nullptr){
        SDL_DestroyWindow(engine.win);
        engine.win = nullptr;
    }
    if (engine.frameFactory != nullptr){
        SDL_DestroyRenderer(engine.frameFactory);
        engine.frameFactory = nullptr;
    }
    engine.window_width = 0;
    engine.window_height = 0;
    SDL_Quit();
}

