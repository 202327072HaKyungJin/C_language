#include <iostream>

class Player {
public:
    Player(float mass, float gravity, float jumpSpeed)
        : mass(mass), gravity(gravity), jumpSpeed(jumpSpeed), velocity(0), position(0), isJumping(false) {}

    void applyGravity(float deltaTime) {
        if (!isJumping) {
            velocity -= gravity * deltaTime;
        }
    }

    void jump() {
        if (!isJumping) {
            velocity = jumpSpeed;
            isJumping = true;
        }
    }

    void update(float deltaTime) {
        applyGravity(deltaTime);

        position += velocity * deltaTime;
        
        if (position <= 0) {
            position = 0;
            velocity = 0;
            isJumping = false;
        }
    }

    float getPosition() const {
        return position;
    }

private:
    float mass;
    float gravity;
    float jumpSpeed;
    float velocity;
    float position;
    bool isJumping;
};

int main() {
    float mass = 1.0f; // 1 kg (for simplicity)
    float gravity = 1.0f; // 1 N of gravitational force
    float jumpSpeed = 5.0f; // 5 m/s jump speed

    Player player(mass, gravity, jumpSpeed);

    float deltaTime = 0.016f; // Assuming 60 FPS, so ~0.016 seconds per frame

    // Simulate for 2 seconds
    for (int i = 0; i < 125; ++i) {
        if (i == 10) { // Jump at the 10th frame
            player.jump();
        }

        player.update(deltaTime);
        std::cout << "Time: " << i * deltaTime << "s, Position: " << player.getPosition() << "m" << std::endl;
    }

    return 0;
}
