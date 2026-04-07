#include "plane.h"
#include <cmath>
#include <iostream>
#include <SDL3/SDL.h>


void Plane::goToWaypoint(Plane& plane)
{
    double dx = waypointX - x;
    double dy = waypointY - y;
    double distance = std::sqrt(dx * dx + dy * dy);
    if (distance > 0) {
        double angleToWaypoint = std::atan2(dy, dx);
        heading = angleToWaypoint; // Update heading towards the waypoint
        x += speed * std::cos(heading);
        y += speed * std::sin(heading);
        
    }
}

void Plane::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &rect);
}