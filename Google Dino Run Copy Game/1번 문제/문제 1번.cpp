#ifndef OBJECT_H
#define OBJECT_H

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
    void draw() {
        // 객체의 내부 색상 설정
        glColor3f(color.r, color.g, color.b);
        // 객체 그리기
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();
    }
};

// 플레이어 클래스 (Object 클래스를 상속)
class Player : public Object {
public:
    Color borderColor; // 테두리 색상
    float borderWidth; // 테두리 두께

    Player(float x, float y, float size, Color color, Color borderColor, float borderWidth)
        : Object(x, y, size, size, color), borderColor(borderColor), borderWidth(borderWidth) {}

    void draw() {
        // 테두리 그리기
        glColor3f(borderColor.r, borderColor.g, borderColor.b);
        glBegin(GL_QUADS);
        glVertex2f(x - borderWidth, y - borderWidth);
        glVertex2f(x + width + borderWidth, y - borderWidth);
        glVertex2f(x + width + borderWidth, y + height + borderWidth);
        glVertex2f(x - borderWidth, y + height + borderWidth);
        glEnd();

        // 내부 정사각형 그리기
        Object::draw();
    }
};

#endif // OBJECT_H
