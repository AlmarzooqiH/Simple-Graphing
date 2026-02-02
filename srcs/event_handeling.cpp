#include "../includes/constants.hpp"

void    performEvent(bool &runingCond, SDL_Event &sdlEvent){
    Uint32 event = sdlEvent.type;
    std::cout << "Event: " << event << std::endl;
    switch (event){
        case (SDL_WINDOWEVENT_CLOSE):
            runingCond = false;
            break ;
        case (SDL_QUIT):
            runingCond = false;
            break ;  
        case (SDL_KEYDOWN):
            SDL_KeyboardEvent pressedKey = sdlEvent.key;
            if (pressedKey.keysym.sym == SDLK_ESCAPE){
                runingCond = false;
            }
            break ;  
        }
}
