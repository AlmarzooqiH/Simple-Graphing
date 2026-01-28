#ifndef CONSTANTS_HPP
# define CONSTANTS_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>

#include <iostream>
#include <string>
#include <cmath>
#include <stdint.h>
#include <charconv>
#include <cstring>

const std::string TITLE("Continues Input Visualizastion");
//I use C as a prefix to constant
constexpr uint16_t      CWIDTH = 800;
constexpr uint16_t      CHEIGHT = 800;
constexpr unsigned int  WINDOW_OPTIONS = SDL_WINDOW_SHOWN | SDL_WINDOW_MOUSE_GRABBED;

// constexpr

#endif