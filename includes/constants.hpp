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
constexpr int       CWIDTH = 800;
constexpr int       CHEIGHT = 800;
constexpr Uint32    WINDOW_OPTIONS = SDL_WINDOW_SHOWN;
constexpr Uint32    MS_TIMEOUT = 25; //This will be used for the SDL_Delay() function.

/**
 * @brief I created this struct the will hold the program data so i wont need to
 * pass a lot of parameters.
 * 
 * @var win Holds a pointer to SDL_Window.
 * @var window_width Holds the width of the window (Default is CWIDTH)
 * @var window_height Holds the height of the window (Default is CHeight)
 * @var frame_factory Holds a pointer to SDL_Renderer which is responsible to draw
 * and plot stuff on the window.
 */
typedef struct GraphicsEngine{
    SDL_Window      *win;
    int             window_width;
    int             window_height;
    SDL_Renderer    *frameFactory;

} GraphicsEngine;

typedef struct s_rgba{
    Uint8 r; // Accepted values are 0 - 255.
    Uint8 g; // Accepted values are 0 - 255.
    Uint8 b; // Accepted values are 0 - 255.
    Uint8 a; // Accepted values are 0 - 255.
} t_rgba;

const t_rgba default_color = {0, 0, 0, 255}; //black

// Event Handlers Functionality
void    performEvent(bool &runingCond, SDL_Event &sdlEvent);

//Frame Rendering Functionality
void    clearFrameBuffer(GraphicsEngine &engine);
void    drawFrame(GraphicsEngine &engine);
void    updateFrame(GraphicsEngine &engine);

//Clean Up Functionality
void    cleanup(GraphicsEngine &engine);
#endif