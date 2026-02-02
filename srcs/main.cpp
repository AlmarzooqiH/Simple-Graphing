#include "../includes/constants.hpp"

int main(int ac, char **av){
    (void)ac;
    (void)av;
    int width = CWIDTH;
    int height = CHEIGHT;
    GraphicsEngine  engine;


    if (ac >= 2) {
        auto widthRes = std::from_chars(av[1], av[1] + std::strlen(av[1]), width);
        if (widthRes.ec != std::errc{}) 
            width = CWIDTH;
    }
    if (ac >= 3) {
        auto heightRes = std::from_chars(av[2], av[2] + std::strlen(av[2]), height);
        if (heightRes.ec != std::errc{})
            height = CHEIGHT;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0){
        std::cerr << "Error Reason: " << SDL_GetError() << std::endl;
        return (2);
    }
    engine.window_width = width;
    engine.window_height = height;
    SDL_Window      *window = nullptr;
    SDL_Renderer    *frameFactory = nullptr;

    SDL_CreateWindowAndRenderer(width, height, WINDOW_OPTIONS, &window, &frameFactory);
    engine.win = window;
    engine.frameFactory = frameFactory;
    if (window == nullptr || frameFactory == nullptr){
        cleanup(engine);
        std::cerr << "Error Reason: " << SDL_GetError() << std::endl;
        return (2);
    }
    SDL_SetWindowTitle(window, TITLE.c_str());
    bool runingCond = true;
    SDL_Event sdlEvent;
    while (runingCond){
        /*
            SDL_PollEvent(SDL_Event& ev); will enter the loop only and only if
            there was an event that triggered it.
        */
        while(SDL_PollEvent(&sdlEvent)){
            performEvent(runingCond, sdlEvent);
            SDL_Delay(MS_TIMEOUT);
        }
        updateFrame(engine);
    }
    cleanup(engine);
    return (0);
}
