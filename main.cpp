#include <SDL.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

struct Vec3
{
    float x, y, z;
};

struct connectP
{
    int a, b;
};

class Screen
{
public:
    SDL_Event e;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    std::vector<SDL_FPoint> points;

    Screen()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer);
        SDL_SetWindowTitle(window, "testing");
    }

    void pixel(float x, float y)
    {
        points.emplace_back(SDL_FPoint{x,y});
    }

    void show()
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 240, 255, 0, 255);
        for (auto& point : points)
        {
            SDL_RenderDrawPointF(renderer, point.x, point.y);
        }
        SDL_RenderPresent(renderer);
    }

    void input()
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
    void clear()
    {
        points.clear();
    }

    void rotate(Vec3& point, float x = 1, float y = 1, float z = 1)
    {
        float radian = 0;
        radian = x;
        point.y = cos(radian) * point.y - sin(radian) * point.z;
        point.z = sin(radian) * point.y + cos(radian) * point.z;

        radian = y;
        point.x = cos(radian) * point.x + sin(radian) * point.z;
        point.z = -sin(radian) * point.x + cos(radian) * point.z;

        radian = z;
        point.x = cos(radian) * point.x - sin(radian) * point.y;
        point.y = sin(radian) * point.x + cos(radian) * point.y;

    }

    void line(Screen& screen, float x1, float y1, float x2, float y2)
    {
        float dx = x2 - x1; // distance between x1 to x2
        float dy = y2 - y1; // distance between y1 to y2

        float length = sqrt(dx * dx + dy * dy);
        float angle = atan2(dy, dx);
        //std::cout << angle << std::endl;
        for (float i = 0; i < length; i++)
        {
            float x = cos(angle) * i + x1;
            float y = sin(angle) * i + y1;
            screen.pixel(x, y);
            if (x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT) break;
        }
    }

};


int main(int argc, char* argv[]) 
{
    Screen screen;

    std::vector<Vec3> points{
        {100, 100, 100},
        {200, 100, 100},
        {200, 200, 100},
        {100, 200, 100},

        {100, 100, 200},
        {200, 100, 200},
        {200, 200, 200},
        {100, 200, 200},
    };

    std::vector<connectP> connectPoint{
        {0, 4},
        {1, 5},
        {2, 6},
        {3, 7},

        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},

        {4, 5},
        {5, 6},
        {6, 7},
        {7, 4},
    };

    while (true)
    {
        for (auto& p : points)
        {
            screen.rotate(p, 0.001, 0.001, 0.001);
            screen.pixel(p.x, p.y);
        }
        for (auto& conp : connectPoint)
        {
            screen.line(screen, points[conp.a].x, points[conp.a].y, points[conp.b].x, points[conp.b].y);
        }
        screen.show();
        screen.clear();
        screen.input();
        SDL_Delay(10);
    }

    return 0;
}
