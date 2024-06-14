#include <SDL2/SDL.h>
#include <vector>
#include <cstdlib>
#include <ctime>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int OBSTACLE_WIDTH = 50;
const int OBSTACLE_HEIGHT = 50;
const int MAX_OBSTACLES = 3;
const int OBSTACLE_SPEED = 5;

struct Obstacle {
    int x, y;
};

void renderObstacle(SDL_Renderer* renderer, Obstacle& obstacle) {
    SDL_Rect rect = { obstacle.x, obstacle.y, OBSTACLE_WIDTH, OBSTACLE_HEIGHT };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &rect);
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Obstacle Game",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    std::vector<Obstacle> obstacles;
    srand(time(0));

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Add a new obstacle if there are less than MAX_OBSTACLES
        if (obstacles.size() < MAX_OBSTACLES) {
            Obstacle newObstacle;
            newObstacle.x = SCREEN_WIDTH;
            newObstacle.y = rand() % (SCREEN_HEIGHT - OBSTACLE_HEIGHT);
            obstacles.push_back(newObstacle);
        }

        // Move obstacles
        for (auto& obstacle : obstacles) {
            obstacle.x -= OBSTACLE_SPEED;
        }

        // Remove obstacles that have moved off-screen
        obstacles.erase(
            std::remove_if(obstacles.begin(), obstacles.end(),
                [](Obstacle& obstacle) { return obstacle.x + OBSTACLE_WIDTH < 0; }),
            obstacles.end()
        );

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);

        for (auto& obstacle : obstacles) {
            renderObstacle(renderer, obstacle);
        }

        SDL_RenderPresent(renderer);

        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
