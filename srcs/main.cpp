#include "../includes/constants.hpp"


int main(int ac, char **av){
    (void)ac;
    (void)av;
    uint16_t width = CWIDTH;
    uint16_t height = CHEIGHT;
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
    SDL_Window  *window = SDL_CreateWindow(TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, WINDOW_OPTIONS);
    if (window == NULL){
        std::cerr << "Failed to intialize the window T_T" << std::endl;
        return (2);
    }

    bool runingCond = true;
    SDL_Event event;
    while (runingCond){
        SDL_PollEvent(&event);
        std::cout << event.type << std::endl;
        switch (event.type){
            case SDL_QUIT:
                SDL_DestroyWindow(window);
                SDL_Quit();
                return (0);
        }
    }
    return (0);
}
