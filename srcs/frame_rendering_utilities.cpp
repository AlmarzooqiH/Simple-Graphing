# include "../includes/constants.hpp"

void    clearFrameBuffer(GraphicsEngine &engine){
    SDL_RenderClear(engine.frameFactory);
}

void    cartesianPlot(GraphicsEngine &engine, int x, int y, const t_rgba color = default_color){

    SDL_SetRenderDrawColor(engine.frameFactory, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(engine.frameFactory,
    (engine.window_width / 2) + (x),
    (engine.window_height / 2) - (y)
    );
}

void    drawFrame(GraphicsEngine &engine){
    SDL_SetRenderDrawColor(engine.frameFactory, 255, 255, 255, 255);
    for (int y = 0; y < engine.window_height; y++){
        SDL_RenderDrawLine(engine.frameFactory, 0, y, engine.window_width, y);
    }
    SDL_SetRenderDrawColor(engine.frameFactory, 0, 0, 0, 255);
    SDL_RenderDrawLine(engine.frameFactory, 0, engine.window_height / 2, engine.window_width, engine.window_height / 2);
    SDL_RenderDrawLine(engine.frameFactory, engine.window_width / 2, 0, engine.window_width / 2, engine.window_height);
    
}

void    updateFrame(GraphicsEngine &engine){
    clearFrameBuffer(engine);
    drawFrame(engine);
    SDL_RenderPresent(engine.frameFactory);
}
