// TransformFunctions.h

#ifndef TRANSFORM_FUNCTIONS_H
#define TRANSFORM_FUNCTIONS_H

struct Vector2D {
    double x;
    double y;

    Vector2D(double x, double y) : x(x), y(y) {}

    // 더하기 연산자 오버로딩
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // 곱하기 연산자 오버로딩 (스칼라)
    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }
};

// 미터 단위 이동 함수 선언
Vector2D translate(const Vector2D& vec, double dx, double dy);

// 각도 단위 시계 방향 회전 함수 선언
Vector2D rotate(const Vector2D& vec, double angleDegrees);

// 미터 단위 배율 조정 함수 선언
Vector2D scale(const Vector2D& vec, double scaleX, double scaleY);

#endif // TRANSFORM_FUNCTIONS_H
