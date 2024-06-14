#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

class Star {
public:
    Star(float x, float y, float size, float speed)
        : size(size), speed(speed) {
        shape.setPosition(x, y);
        shape.setRadius(size);
        shape.setFillColor(sf::Color::White);
    }

    void update(float deltaTime) {
        shape.move(0, speed * deltaTime);
        if (shape.getPosition().y > 600) { // Reset star position if it moves off the bottom of the screen
            shape.setPosition(shape.getPosition().x, -shape.getRadius());
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

private:
    float size;
    float speed;
    sf::CircleShape shape;
};

int main() {
    // Initialize random seed
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Stars");

    // Create stars
    std::vector<Star> stars;
    for (int i = 0; i < 5; ++i) {
        float x = static_cast<float>(std::rand() % window.getSize().x);
        float y = static_cast<float>(std::rand() % window.getSize().y);
        float size = static_cast<float>(std::rand() % 10 + 5); // Star sizes between 5 and 15
        float speed = 100.0f / 3; // Assuming block speed is 100 units per second, star speed is 1/3 of that
        stars.emplace_back(x, y, size, speed);
    }

    // Clock for timing
    sf::Clock clock;

    // Main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Calculate delta time
        float deltaTime = clock.restart().asSeconds();

        // Update stars
        for (auto& star : stars) {
            star.update(deltaTime);
        }

        // Clear the window
        window.clear();

        // Draw stars
        for (const auto& star : stars) {
            star.draw(window);
        }

        // Display the window
        window.display();
    }

    return 0;
}
