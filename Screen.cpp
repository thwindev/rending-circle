#include "Screen.h"

Screen::Screen(Points& _points)
    :points(_points)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer);
    SDL_SetWindowTitle(window, "Rendering Circle");
}

void Screen::show()
{

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    setCoordinate();

    SDL_SetRenderDrawColor(renderer, 240, 255, 0, 255);

    for (auto& i : points.ps)
    {
        SDL_RenderDrawPointF(renderer, i.x, i.y);
    }

    SDL_RenderPresent(renderer);
}

void Screen::input()
{
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            SDL_Quit();
            exit(0);
        }
    }
}

float Screen::circlePoint(Points& p1,Points& p2)
{
    float d1 = (p2.x - p1.x) * (p2.x - p1.x);
    float d2 = (p2.y - p1.y) * (p2.y - p1.y);
    float distance = sqrt(d1 + d2);

    return distance;
}

void Screen::setCoordinate()
{
    Points midPoint = points.getPointLocation(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Points radiusPoint = points.getPointLocation(300, 200);

    // create radius points depend on circumstance length 
    float distance = circlePoint(midPoint, radiusPoint);
    // find the circumstance of circle
    int circumstance = 2 * M_PI * distance;
    //std::cout << circumstance << std::endl;

    for (int i = 0; i < circumstance; i++)
    {
        // find the angle depend on the number of points
        float theta = 2 * M_PI * i / points.numberPoints;

        // get the position of coordinate for x axis 
        float x = midPoint.x + (distance * cos(theta));
        // get the position of coordinate for y axis 
        float y = midPoint.x + (distance * sin(theta));

        // set every coordinate values to vector
        points.pixel(x, y);
    }
}
