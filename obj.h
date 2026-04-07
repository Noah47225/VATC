#pragma once

#include <SDL3/SDL.h>

class GameObject {

public:
    SDL_FRect rect;
    double hight = rect.h;
    double width = rect.w;
    

    // C++ Constructor using an Initializer List
    GameObject(float x, float y, float w, float h)
        : rect{x, y, w, h} {}

    // Virtual destructor is vital in C++ OOP
    virtual ~GameObject() = default;

    // Virtual render method
    

};
