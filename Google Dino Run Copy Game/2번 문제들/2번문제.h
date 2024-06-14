#pragma once

#include <GLFW/glfw3.h>

// 색상을 저장하는 구조체
struct Color {
    float r, g, b;
    Color(float red, float green, float blue) : r(red), g(green), b(blue) {}
};

// 객체를 나타내는 클래스
class Object {
public:
    float x, y; // 위치
    float width, height; // 크기
    Color color; // 색상

    Object(float x, float y, float width, float height, Color color)
        : x(x), y(y), width(width), height(height), color(color) {}

    // 객체를 그리는 함수
    virtual void draw() {
        // 내부 색상 설정
        glColor3f(color.r, color.g, color.b);
        // 내부 색으로 사각형 그리기
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();
    }
};

// 플레이어 클래스 (Object를 상속)
class Player : public Object {
public:
    Player(float x, float y)
        : Object(x, y, 50.0f, 50.0f, Color(1.0f, 0.0f, 0.0f)) {} // 빨강색 정사각형

    void draw() override {
        // 플레이어 객체의 테두리 그리기
        glColor3f(1.0f, 1.0f, 1.0f); // 흰색 테두리
        glBegin(GL_QUADS);
        glVertex2f(x - 3.0f, y - 3.0f);
        glVertex2f(x + width + 3.0f, y - 3.0f);
        glVertex2f(x + width + 3.0f, y + height + 3.0f);
        glVertex2f(x - 3.0f, y + height + 3.0f);
        glEnd();

        // 기본적으로 Object의 draw 함수 호출하여 내부 색상 사각형 그리기
        Object::draw();
    }
};

// 지면 클래스 (Object를 상속)
class Ground : public Object {
public:
    Ground()
        : Object(0.0f, 100.0f, 800.0f, 100.0f, Color(1.0f, 200.0f / 255.0f, 15.0f / 255.0f)) {} // 황색 바닥

    void draw() override {
        // 지면 객체의 내부 색상 사각형 그리기
        Object::draw();
    }
};

// 장애물 클래스 (Object를 상속)
class Obstacle : public Object {
public:
    Obstacle(float x, float y, float height)
        : Object(x, y, 50.0f, height, Color(0.0f, 1.0f, 0.0f)) {} // 녹색 장애물

    void draw() override {
        // 장애물 객체의 내부 색상 사각형 그리기
        Object::draw();
    }
};
