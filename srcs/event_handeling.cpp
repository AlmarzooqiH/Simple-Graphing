#include "../includes/constants.hpp"

void    performEvent(bool &runingCond, SDL_Event &sdlEvent){
    Uint32 event = sdlEvent.type;
    switch (event){
        case SDL_WINDOWEVENT_CLOSE:
            runingCond = false;
            break;
        case SDL_QUIT:
            runingCond = false;
            break ;    
        }
}
