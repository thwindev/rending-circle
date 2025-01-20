#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>
#include <math.h>

#include "Points.h"

class Screen
{
public:
    SDL_Event e;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    const int SCREEN_WIDTH = 600;
    const int SCREEN_HEIGHT = 600;

    //point
    Points& points;


public:
    Screen(Points& points);

    void show();
    void input();

    float circlePoint(Points& p1,Points& p2);
    void setCoordinate();
};