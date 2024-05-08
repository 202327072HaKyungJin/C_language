#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define PI 3.14159265

float moveFactor = 0.0f;
float rotationSpeed = 0.01f; // 회전 속도 조절

void errorCallback(int error, const char* description)
{
    printf("\033[1;31mGLFW Error: %s \033[0m\n");
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void drawCircle(float centerX, float centerY, float radius, int segments)
{
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * PI * i / segments;
        float x = centerX + radius * std::cos(theta); // 삼각함수와 원주율 사용
        float y = centerY + radius * std::sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

int update()
{
    moveFactor += rotationSpeed; // 회전 각도 갱신
    return 0;
}

int render()
{
    glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    int width, height;
    glfwGetFramebufferSize(glfwGetCurrentContext(), &width, &height);

    glViewport(0, 0, width, height); // 뷰포트 설정

    // 원 그리기
    float centerX = 0.0f; // 원의 중심 좌표
    float centerY = 0.0f;
    float radius = 0.5f; // 반지름
    int segments = 100; // 원을 근사하기 위한 세그먼트 수

    glColor3f(1.0f, 1.0f, 1.0f); // 흰색으로 설정
    glLoadIdentity(); // 초기화
    glOrtho(-1.0, 1.0, -1.0 * (GLfloat)height / (GLfloat)width, 1.0 * (GLfloat)height / (GLfloat)width, -1.0, 1.0); // 좌표 시스템 설정
    glTranslatef(centerX, centerY, 0.0f); // 중심점으로 이동
    glRotatef(moveFactor * 180.0f / PI, 0.0f, 0.0f, 1.0f); // 회전
    drawCircle(0.0f, 0.0f, radius, segments); // 원 그리기

    return 0;
}

int main(void)
{
    // GLFW 라이브러리 초기화
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(800, 600, "Rotating Circle", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        update();
        render();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}


#include <cmath> // 삼각함수 사용을 위한 헤더 추가

double starRotationAngle = 0.0; // 별의 회전 각도

// 별 회전 함수
void rotateStar(double angle)
{
    starRotationAngle += angle;
}

// 렌더링 함수 내에서 별을 회전시키는 부분 수정
glPushMatrix();
glTranslatef(starPositionX, starPositionY, 0.0f); // 별의 위치에 따라 이동
glRotatef(starRotationAngle, 0.0f, 0.0f, 1.0f); // 회전 적용
glScalef(scaleFactor, scaleFactor, 1.0); // 확대/축소 적용
render(); // 삼각형 렌더링
glPopMatrix();
/