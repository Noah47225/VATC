#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "plane.h"
#include <iostream>
#include <cmath>
#include "obj.h"
#include <SDL3/SDL_video.h>

 





int main(int argc, char* argv[]) {
    if (!SDL_Init(SDL_INIT_VIDEO)) return -1;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    if (!SDL_CreateWindowAndRenderer("Simple SDL3 Window", 1200, 600, 0, &window, &renderer)) {
        SDL_Quit();
        return -1;
    }
      
    Plane player(100.0, 100.0, 0.0, 10000.0, 5.0);
    player.waypointX = 500.0;
    player.waypointY = 300.0;

    bool isRunning = true;
    Uint32 lastTime = SDL_GetTicks();
    while (isRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) isRunning = false;
        }

        // --- 2. UPDATE LOGIC ---
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        
        player.goToWaypoint(player);
        player.rect.x = player.x;
        player.rect.y = player.y;
        
        
        
        lastTime = currentTime;
        //RENDER ---
        SDL_SetRenderDrawColor(renderer, 50, 100, 150, 255); 
        SDL_RenderClear(renderer);
        // DRAW THE OBJECTS
        std::cout << "Player Position: (" << player.rect.x << ", " << player.rect.y << ")\n";
        player.render(renderer);

        // Present to screen
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
