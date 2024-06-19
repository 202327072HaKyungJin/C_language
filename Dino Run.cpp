#pragma once

#include <GLFW/glfw3.h>
#include <GL/gl.h>

class Object {
public:
    virtual void Draw() = 0;
};

class Player : public Object {
private:
    int x, y;
    int size;
    float velocity; // 플레이어의 수직 속도
    bool jumping;   // 점프 중인지 여부

public:
    Player(int x, int y, int size) : x(x), y(y), size(size), velocity(0.0f), jumping(false) {}

    void Draw() override {
        // 플레이어 본체 그리기 (빨강색)
        glColor3ub(255, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(x, y);
        glVertex2i(x + size, y);
        glVertex2i(x + size, y + size);
        glVertex2i(x, y + size);
        glEnd();

        // 플레이어 테두리 그리기 (검정색)
        glColor3ub(0, 0, 0);
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2i(x, y);
        glVertex2i(x + size, y);
        glVertex2i(x + size, y + size);
        glVertex2i(x, y + size);
        glEnd();
    }

    void Update() {
        // 중력 적용
        if (y > 0) {
            velocity -= 9.8f * 0.01f; // 중력 가속도 (1N)
            y += static_cast<int>(velocity * 10.0f); // 위치 업데이트
        }
        else {
            y = 0; // 바닥에 닿으면 더 이상 내려가지 않도록 함
            velocity = 0.0f;
            jumping = false;
        }
    }

    void Jump() {
        if (!jumping) {
            velocity = 0.5f; // 점프력 (속도로 환산시 5m/s)
            jumping = true;
        }
    }
};

class Floor : public Object {
private:
    float height; // 바닥 높이

public:
    Floor(float height) : height(height) {}

    void Draw() override {
        glColor3ub(255, 200, 15); // 황색 (R:255, G:200, B:15)
        glBegin(GL_QUADS);
        glVertex2f(0, height);          // 왼쪽 아래
        glVertex2f(800, height);        // 오른쪽 아래
        glVertex2f(800, 0);             // 오른쪽 위
        glVertex2f(0, 0);               // 왼쪽 위
        glEnd();
    }
};

class EnemyBlock : public Object {
private:
    float x, y; // 장애물 위치 (x는 가로, y는 세로)
    float width, height; // 장애물 크기 (가로, 세로)

public:
    EnemyBlock(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {}

    void Draw() override {
        glColor3ub(0, 255, 0); // 녹색 (R:0, G:255, B:0)
        glBegin(GL_QUADS);
        glVertex2f(x, y);           // 왼쪽 아래
        glVertex2f(x + width, y);   // 오른쪽 아래
        glVertex2f(x + width, y + height); // 오른쪽 위
        glVertex2f(x, y + height);  // 왼쪽 위
        glEnd();
    }
};